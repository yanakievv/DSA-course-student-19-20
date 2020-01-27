#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int N;
    int * walls;
    int tempvolume = 0;
    int maxvolume = 0;
    int distance = 1;
    
    std::cin>>N;
    walls = new int[N];
    for (int i = 0; i < N; i++)
    {
        std::cin>>walls[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            int minheight;
            
            if (walls[i] >= walls[j])
            {
                minheight = walls[j];
            }
            else
            {
                minheight = walls[i];
            }
            
            tempvolume = minheight*((j-i)*distance);
            
            if (tempvolume > maxvolume)
            {
                maxvolume = tempvolume;
            }
        }
    }
    
    std::cout<<maxvolume;
    return 0;
}
