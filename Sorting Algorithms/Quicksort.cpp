#include <iostream>
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int* arr, int l, int r)
{
	int pivot = arr[r];
	int pivotindex = l;
	for (int i = l; i <= r; i++)
	{
		if (arr[i] < pivot)
		{
			swap(arr[i], arr[pivotindex]);
			pivotindex++;
		}
	}
	swap(arr[r], arr[pivotindex]);
	return pivotindex;
}

void _quicksort(int* arr, int l, int r)
{
	if (l < r)
	{
		int pivot = partition(arr, l, r);
		_quicksort(arr, l, pivot - 1);
		_quicksort(arr, pivot + 1, r);
	}
}

void quickSort(int* arr, int lenght)
{
	_quicksort(arr, 0, lenght - 1);
}

int main() 
{

    int arr[] = {3, 4, 1, 5, 2, 6};
    
    quickSort(&arr[0], 6);

    for (int i = 0; i < 6; i++) 
    {
        std::cout << arr[i] << ", ";

    }
}
