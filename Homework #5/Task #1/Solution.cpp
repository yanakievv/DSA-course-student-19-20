#include <iostream>
struct Node
{
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    
};
struct Tree
{
    Node* root = nullptr;
    void _insertkey(int key, Node* root,Node* insertafter)
    {
        if (root != nullptr)
        {
            if (root->key < key)
            {
                _insertkey(key,root->right,root);
            }
            else if (root->key > key)
            {
                _insertkey(key,root->left,root);
            }
            else
            {
                return;
            }
        }
        else
        {
            if (insertafter->key < key)
            {
                Node* temp = new Node;
                temp->key = key;
                insertafter->right = temp;
            }
            else
            {
                Node* temp = new Node;
                temp->key = key;
                insertafter->left = temp;
            }
        }
    }
    int calculateDistance(int key, Node* root, int count)
    {
        if (root->left != nullptr && root->key > key)
        {
            count++;
            return calculateDistance(key,root->left,count);
        }
        else if (root->right != nullptr && root->key < key)
        {
            count++;
            return calculateDistance(key,root->right,count);
        }
        else if (root->key == key)
        {
            return count;
        }
        else return -1;
    }
    void insertKey(int key)
    {
        if (root == nullptr)
        {
            root = new Node;
            root->key = key;
        }
        else
        {
            _insertkey(key,root,root);
        }
    }
    
};
int main()
{
    int N;
    int K;
    std::cin>>N;
    std::cin>>K;
    Tree city;
    for (int i = 0; i < N; i++)
    {
        int temp;
        std::cin>>temp;
        city.insertKey(temp);
    }
    for (int i = 0; i < K; i++)
    {
        int temp;
        std::cin>>temp;
        int distance = city.calculateDistance(temp,city.root,0);
        std::cout<<distance<<std::endl;
    }
}
