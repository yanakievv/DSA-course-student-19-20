#include <iostream>
#include <math.h>

int search(long int* arr,long int target, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        if (arr[i] >= target)
        {
            return i;
        }
    }
    return -1;
}

int jump_search(long int* cups,long int target, int lenght)
{
    int step = (int)floor(sqrt(lenght - 1));
    for (int i = step; i < lenght; i += step)
    {
        if (cups[i] >= target)
        {
            return search(cups, target, i - step, i);
        }
    }
    
    return search(cups, target, lenght - step - 1, lenght - 1);


}



int main()
{
    int n;
    int m;
    std::cin >> n;
    long int* cups = new long int[n];
    long int temp = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        std::cin >> j;
        cups[i] = temp + j;
        temp = cups[i];

    }

    std::cin >> m;
    long int* targets = new long int[m];
    for (int i = 0; i < m; i++)
    {
        std::cin >> targets[i];
    }

    for (int i = 0; i < m; i++)
    {
        std::cout << jump_search(cups, targets[i], n) + 1 <<std::endl;
    }



}
