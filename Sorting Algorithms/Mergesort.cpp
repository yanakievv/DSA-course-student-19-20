#include <iostream>

void merge(int* arr, int* mergearr, int start, int mid, int end)
{
	int left = start;
	int right = mid + 1;

	for (int i = start; i <= end; i++)
	{
		if (left <= mid && (right > end || arr[left] <= arr[right]))
		{
			mergearr[i] = arr[left];
			left++;
		}
		else
		{
			mergearr[i] = arr[right];
			right++;
		}
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = mergearr[i];
	}
}

void _mergesort(int* arr, int*mergearr, int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		_mergesort(arr, mergearr, l, mid);
		_mergesort(arr, mergearr, mid + 1, r);

		merge(arr, mergearr, l, mid, r);
	}
}

void mergeSort(int* arr, int lenght)
{
	int* mergearr = new int[lenght];
	_mergesort(arr, mergearr, 0, lenght - 1);
	delete[] mergearr;
}

int main() 
{

    int arr[] = {3, 4, 1, 5, 2, 6};
    
    mergeSort(&arr[0], 6);

    for (int i = 0; i < 6; i++) 
    {
        std::cout << arr[i] << ", ";

    }
}
