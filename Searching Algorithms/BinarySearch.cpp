#include <iostream>

int _binarySearch(int* array, int left, int right, int target) 
{
    if (right - left < 0)
    {
        return -1;
    }

    int mid = (right + left) / 2;
    
    if (array[mid] == target)
    {
        return mid;
    } 
    else if (array[mid] > target) 
    {
        return _binarySearch(array, left, mid - 1, target);
    } 
    else if (array[mid] < target)
    {
        return _binarySearch(array, mid + 1, right, target);
    }

    return -1;
}



int binarySearch(int *array, int length, int target) 
{
    return _binarySearch(array, 0, length - 1, target);
}



int main() 
{

    int arr[] = {0, 1, 2, 3, 4, 5};
    
    std::cout << "Index of 4 is " << binarySearch(&arr[0], 6, 4) << std::endl;
    std::cout << "Index of 10 is " << binarySearch(&arr[0], 6, 10) << std::endl;

}
