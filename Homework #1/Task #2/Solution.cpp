#include <iostream>
int main()
{
    int M;
    int N;
    long int * grade;

    std::cin >> M;
    std::cin >> N;
    grade = new long int[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> grade[i];
    }


    long int neededscore = N*M;
    long int totalscore = 0;

    for (int i = 0; i < N; i++)
    {
        totalscore += grade[i];
    }

    if (totalscore >= neededscore)
    {
        std::cout<<"yes";
    }
    else
    {
        std::cout<<"no";
    }
    

}
