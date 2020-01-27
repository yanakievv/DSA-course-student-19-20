#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Node
{
    char letter = 0;
    std::vector<Node*> next;
    bool isfullword = false;
    friend class Trie;
    
    Node() = default;
    Node(char letter)
    {
        this->letter = letter;
    }
    
    int containsAndReturnIndex(char x)
    {
        for (int i = 0; i < next.size(); i++)
        {
            if (next[i]->letter == x)
            {
                return i;
            }
        }
        return -1;
    }
    void addletter(char letter)
    {
        if (containsAndReturnIndex(letter) < 0)
        {
            next.push_back(new Node(letter));
        }
    }
    
    int searchwords()
    {
        int ctr = 0;
        queue<Node*> Q;
        Q.push(this);
        while(!Q.empty())
        {
            Node* temp = Q.front();
            Q.pop();
            for (int i = 0; i < temp->next.size(); i++)
            {
                if (temp->next[i]->isfullword)
                {
                    ctr++;
                }
                Q.push(temp->next[i]);
            }
        }
        return ctr;
    }
    
    private:
    void addNewLetter(char letter)
    {
        next.push_back(new Node(letter));
    }
    
};
class Trie
{
    Node* root = nullptr;
    
    public:
    Trie() = default;
    Trie(char letter)
    {
        root = new Node(letter);
    }
    ~Trie()
    {
        delete[] root;
    }
    
    void addword(char* word)
    {
        Node* temp = root;
        for (int i = 1; i < strlen(word); i++)
        {
            int index = temp->containsAndReturnIndex(word[i]);
            if (index < 0)
            {
                temp->addNewLetter(word[i]);
                temp = temp->next[temp->next.size() - 1];
            }
            else
            {
                temp = temp->next[index];
            }
        }
        temp->isfullword = true;
    }
    
    void search(char* word)
    {
        Node* temp = root;
        int ctr = 0;
        for (int i = 1; i < strlen(word); i++)
        {
            int index = temp->containsAndReturnIndex(word[i]);
            if (index >= 0)
            {
                temp = temp->next[index];
            }
            else
            {
                printf("%d\n",ctr);
                return;
            }
        }
        if (temp->isfullword)
        {
            ctr++;
        }
        ctr += temp->searchwords();
        printf("%d\n",ctr);
    }
    

    
};

int main() {
    std::vector<Trie*> alphabet;
    for (int i = 0; i < 26; i++)
    {
        alphabet.push_back(new Trie((char)(i + 97)));
    }
    int N;
    int Q;
    char* temp = new char[20];
    std::cin>>N>>Q;
    for (int i = 0; i < N; i++)
    {
        scanf("%s",temp);
        alphabet[(int)(temp[0]) - 97]->addword(temp);
    }
    for (int i = 0; i < Q; i++)
    {
        scanf("%s",temp);
        alphabet[(int)(temp[0]) - 97]->search(temp);
    }
    
    return 0;
}
