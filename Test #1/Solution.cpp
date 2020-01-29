#include <iostream>
void counting(int* arr, int lenght)
{
    int* sortedarr = new int[lenght + 1];
    int max = 0;
    for (int i = 0; i < lenght + 1;i++)
    {
        if (max>arr[i])
        {
            max = arr[i];
        }
        if (i < lenght)
        {
            sortedarr[i] = 0; 
        }

    }
    for (int i = 0; i < lenght; i++)
    {
        sortedarr[arr[i]]++;
    }
    
    int indx = 0;
    
    for (int i = lenght - 1; i >= 0; i--)
    {
        while(sortedarr[indx] == 0)
        {
            indx++;
        }
        arr[i] = indx;
        sortedarr[indx]--;
    }
}
int main() 
{
    int n;
    std::cin>>n;
    int* arr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }
    
    counting(arr,n);
    
    for (int i = 0; i < n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
     
    return 0;
}
