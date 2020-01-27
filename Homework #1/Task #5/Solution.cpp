#include <iostream>
struct Board
{
    int value;
    int multiplier;
    int total;

    Board(int value = 0, int multiplier = 1, int total = 0) : value(value), multiplier(multiplier), total(total)
    {

    }
    void setvalue(int value)
    {
        this->value = value;
    }
    void setmulti(int multi)
    {
        multiplier = multi;
    }
    void settotal(int total)
    {
        this->total = total;
    }
};

int main()
{
    int score = 0;
    int N;
    int ctr = 0;
    Board variations[63];

    std::cin >> N;

    for (int i = 1, j = 1; j <= 20 && i < 61 ; j++)
    {
        variations[i].setvalue(j);
        variations[i].setmulti(1);
        variations[i].settotal(j);
        i++;

        variations[i].setvalue(j);
        variations[i].setmulti(2);
        variations[i].settotal(2*j);
        i++;

        variations[i].setvalue(j);
        variations[i].setmulti(3);
        variations[i].settotal(3*j);
        i++;
    }
    variations[61].settotal(25);
    variations[62].settotal(50);

    for (int i = -1; i < 63; i+=3)
    {
        score = 0;
        if (i == 61) i++;
        if (i == -1) continue;
        
        score += variations[i].total;
        if (score == N) ctr++;

        for (int j = 0; j < 63; j++)
        {
            score += variations[j].total;
            if (score == N) ctr++;

            for (int k = 0; k < 63; k++)
            {
                score += variations[k].total;
                if (score == N) ctr++;

                score -= variations[k].total;

            }
            score -= variations[j].total;
        }
        
    }

    std::cout << ctr;
}
