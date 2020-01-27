#include <iostream>

int main()
{
    long int original;
    long int clones;
    long int N;
    long int M;
    short T;
    bool* results;
    
    std::cin >> T;
    if (!(T>=1 && T<=10))
    {
        std::cout<<"T must be between 0 and 10";
        return 0;
    }
    results = new bool[T];
    
    for (short i = 0; i < T; i++)
    {
        original = 1;
        clones = 0;
        
        std::cin >> N;
        std::cin >> M;

        for (long int j = original; j < M; j++)
        {
            original++;
            clones++;
        }

        if (clones != 0)
        {
            for (long int j = clones; j < N - 1; j += 2)
            {
               clones += 2;
            } 
        }

        if (original == M && clones == N)
        {
            results[i] = true;
        }
        else
        {
            results[i] = false;
        }
    }

    for (int i = 0; i < T; i++)
    {
        if (results[i]) std::cout<<"yes"<<std::endl;
        else std::cout<<"no"<<std::endl;
    }
}
