#include <iostream>
void merge(int* arr, int*mergearr, int start, int mid, int end)
{
    int l = start;
    int r = mid + 1;

    for (int i = start; i <= end; i++)
    {
        if (l <= mid && (r > end || arr[l] <= arr[r]))
        {
            mergearr[i] = arr[l];
            l++;
        }
        else
        {
            mergearr[i] = arr[r];
            r++;
        }
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = mergearr[i];
    }

}
void _mergesort(int* arr, int* mergearr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        _mergesort(arr, mergearr, start, mid);
        _mergesort(arr, mergearr, mid + 1, end);

        merge(arr, mergearr, start, mid, end);
    }
}
void mergesort(int* arr, int lenght)
{
    int* mergearr = new int[lenght];
    _mergesort(arr, mergearr, 0, lenght - 1);
    delete[] mergearr;
}

int main()
{
    int dead = 0;
    int ctr = 0;
    int n;
    int x;
    std::cin >> n;
    std::cin >> x;
    int* monsters = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> monsters[i];
    }

    mergesort(monsters, n);

    for (int i = n - 1; i > 0; i--)
    {
        
        if (monsters[i] > 0 && monsters[i] != monsters[i - 1])
        {
   
            if (monsters[i] > ctr*x)
            {
                ctr++;
            }
            else
            {
                break;
            }
        }    
    }

    std::cout << ctr;

}
