#include <iostream>
#include <string>
int main()
{
    bool ispermutation = true;
    int N;
    std::string word1;
    std::string word2;
    char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    int counter1[26];
    int counter2[26];
    for (int i = 0; i < 26; i++)
    {
        counter1[i] = 0;
        counter2[i] = 0;
    }
    std::cin >> N;
    std::cin >> word1;
    std::cin >> word2;

    for (int i = 0; i < word1.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (word1[i] == alphabet[j])
            {
                counter1[j]++;
            }
            if (word2[i] == alphabet[j])
            {
                counter2[j]++;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (counter1[i] != counter2[i])
        {
            ispermutation = false;
        }
    }

    if (ispermutation) std::cout << "yes";
    else std::cout << "no";

}
