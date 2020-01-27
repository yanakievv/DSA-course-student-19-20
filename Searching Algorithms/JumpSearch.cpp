#include <iostream>
#include <cmath>

int jumpSearch(int *array, int length, int target) 
{
   int left = 0;
   int step = sqrt(length);
   int right = step;

   while(right < length && array[right] <= target) 
   {
      left += step;
      right += step;
      if(right > length - 1)
      {
         right = length;
      }
   }

   for(int i = left; i < right; i++) 
   {
      if(array[i] == target)
      {
          return i;
      }
   }
   
   return -1;
}



int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    
    std::cout << "Index of 4 is " << jumpSearch(&arr[0], 6, 4) << std::endl;
    std::cout << "Index of 10 is " << jumpSearch(&arr[0], 6, 10) << std::endl;
}
