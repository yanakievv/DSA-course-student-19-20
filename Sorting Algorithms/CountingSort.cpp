#include <iostream>



void countingSort(int * array, int length) 
{
    int maxNumber = 0;

    for (int i = 0; i < length; i++) 
    {
        if (array[i] > maxNumber) 
        {
            maxNumber = array[i];
        }
    }
    int* countingArray = new int[maxNumber + 1];

    for (int i = 0; i < maxNumber + 1; i++) 
    {
        countingArray[i] = 0;
    }

    for (int i = 0; i < length; i++) 
    {
        countingArray[array[i]]++;
    }

    int sortedIndex = 0;

    for (int i = 0; i < length; i++) 
    {
        while (countingArray[sortedIndex] == 0) 
        {
            sortedIndex++;
        }
        
        array[i] = sortedIndex;
        countingArray[sortedIndex]--;
    }
    
    delete[] countingArray;
}



int main() 
{

    int arr[] = {3, 4, 1, 5, 2, 6};
    
    countingSort(&arr[0], 6);

    for (int i = 0; i < 6; i++) 
    {
        std::cout << arr[i] << ", ";

    }
}
