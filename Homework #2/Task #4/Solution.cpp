#include <iostream>
struct subject
{
    int start;
    int duration;
    int end;
    
};

int calculate(subject* sortedarr,int lenght)
{
    int temp;
    int ctr = 0;
    for (int i = 0; i < lenght;)
    {
        temp = sortedarr[i].end;
        ctr++;
        for (int j = i + 1; j < lenght; j++)
        {

            if (temp <= sortedarr[j].start)
            {
                i = j;
                break;
            }
            else if (j == lenght - 1)
            {
                return ctr;
            }
        }
    }
    return ctr;
}

void swapsubjects(subject& a, subject& b)
{
    subject temp = a;
    a = b;
    b = temp;
}
int partition(subject*arr, int l, int r)
{
    subject temp;
    int pivot = arr[r].end;
    int pivotindex = l;
    for (int i = l; i <= r; i++)
    {
        if (arr[i].end < pivot)
        {
            //swapsubjects(arr[i], arr[pivotindex]);
            temp = arr[i];
            arr[i] = arr[pivotindex];
            arr[pivotindex] = temp;
            pivotindex++;
        }
    }

    swapsubjects(arr[r], arr[pivotindex]);
    return pivotindex;
}

void _quicksort(subject* arr, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);
        _quicksort(arr, l, pivot - 1);
        _quicksort(arr, pivot + 1, r);
    }
}

void quicksort(subject* arr, int lenght)
{
    _quicksort(arr, 0, lenght - 1);
}

int main()
{
    int N;
    int temp;
    scanf("%i", &N);
    subject arr[1000000];
    for (int i = 0; i < N; i++)
    {
        scanf("%i", &temp);
        arr[i].start = temp;
        scanf("%i", &temp);
        arr[i].duration = temp;
        arr[i].end = arr[i].start + arr[i].duration;
        
    }

    quicksort(arr, N);
    std::cout<<calculate(arr,N);
}
