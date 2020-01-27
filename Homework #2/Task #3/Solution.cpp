#include <iostream>
long int ctr = 0;
void merge(int* arr, int*temparr, int start, int mid, int end)
{
    int l = start;
    int r = mid + 1;

    for (int i = start; i <= end; i++)
    {
        if (l <= mid && (r > end || arr[l] < arr[r]))
        {
            temparr[i] = arr[l];
            l++;
        }
        else
        {
            temparr[i] = arr[r];
            r++;
            ctr+= mid - l + 1;
        }
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temparr[i];
    }
}
void _mergesort(int* arr, int* temparr,int start,int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        _mergesort(arr, temparr, start, mid);
        _mergesort(arr, temparr, mid + 1, end);

        merge(arr, temparr, start, mid, end);
    }
}
void mergesort(int* arr, int lenght)
{
    int *temparr = new int[lenght + 1];
    _mergesort(arr, temparr, 0, lenght - 1);
    delete[] temparr;
}

int main()
{
    int N;
    std::cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
    mergesort(arr,N);
    std::cout<<ctr;
}
