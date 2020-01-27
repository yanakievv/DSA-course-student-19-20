#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main()
{
    int N;
    std::cin >> N;

    int ctr = 0;
    std::unordered_map<int, int> keys;
    int* arr = new int[N - 1];

    for (int i = 0; i < N - 1; i++)
    {
        int temp;
        std::cin >> temp;

        arr[i] = temp;
    }

    keys.insert({ arr[0], 1});

    for (int i = 0; i < N - 1; i++)
    {
        int temp;
        std::cin >> temp;

        auto it = keys.find(temp);

        if (it == keys.end())
        {
            ctr++;

            auto it1 = keys.find(arr[i + 1]);
            
            if (it1 == keys.end())
            {   
                keys.insert({ arr[i + 1], 1});
            }
            else
            {
                 keys[arr[i + 1]]++;
            }
        }
        else
        {
            if (it->second > 1)
            {
                keys[temp]--;
            }
            else
            {
                keys.erase(temp);
            }

            auto it1 = keys.find(arr[i + 1]);
            
            if (it1 == keys.end())
            {
                keys.insert({ arr[i + 1], 1 });
            }
            else
            {
                 keys[arr[i + 1]]++;
            }
        }
    }

    std::cout << ctr;
    return 0;
}
