#include <stdio.h>
#include <vector>
#include <bits/stdc++.h> 

double getMedian(double num, double med, std::priority_queue<double> &max, std::priority_queue <double, std::vector<double>, std::greater<double> > &min)
{
    int sizeMin = min.size();
    int sizeMax = max.size();
    if (sizeMax > sizeMin)
    {
        if (num < med)
        {
            min.push(max.top());
            max.pop();
            max.push(num);
        }
        else
        {
            min.push(num);
        }
        
        med = (max.top() + min.top()) / 2;
    }
    else if (sizeMax == sizeMin)
    {
        if (num < med)
        {
            max.push(num);
            med = max.top();
        }
        else
        {
            min.push(num);
            med = min.top();
        }
    }
    else
    {
        if (num < med)
        {
            max.push(num);
        }
        else
        {
            max.push(min.top());
            min.pop();
            min.push(num);
        }
        med = (max.top() + min.top()) / 2;
    }
    return med;
}
void printMedian(double* arr, int size)
{
    double med = 0;
    std::priority_queue<double>* max = new std::priority_queue<double>;
    std::priority_queue <double, std::vector<double>, std::greater<double> >* min = new std::priority_queue <double, std::vector<double>, std::greater<double> >; 
    for (int i = 0; i < size; i++)
    {
        med = getMedian(arr[i],med,*max,*min);
        //std::cout<<std::fixed<<std::setprecision(1)<<med<<std::endl;
        printf("%.1f \n", med);
    }

}
int main()
{
    int N;
    std::cin>>N;
    double* arr = new double[N];
    for (int i = 0; i < N; i++)
    {
        std::cin>>arr[i];
    }
    printMedian(arr,N);
}
