#include <iostream>
#include <stack>
struct tree
{
    int index;
    int visible = 0;

};

int max(int* trees, tree pos, int lenght)
{
    int height = trees[pos.index];
    for (int i = pos.index + 1; i < lenght; i++)
    {
        if (trees[i] > height)
        {
            pos.visible++;
            height = trees[i];
        }
    }
    return pos.visible;

}

int main()
{
    std::stack<tree> pos;
    int temp;
    int N;
    scanf("%i", &N);
    int* trees = new int[N];
    for (int i = 0; i < N; i++)
    {
        tree tempvis;
        scanf("%i", &trees[i]);
        if (i == 0)
        {
            tempvis.index = 0;
            pos.push(tempvis);
        }
        else if (trees[i] < trees[i - 1])
        {
            tempvis.index = i;
            pos.push(tempvis);
        }
    }
    int tempmax = 0;
    int tempindex;
    while (!pos.empty())
    {
        int tempfunc = max(trees,pos.top(),N);
        if (tempfunc >= tempmax)
        {
            tempindex = pos.top().index;
            tempmax = tempfunc;
        }
        pos.pop();
        if (!pos.empty() && tempfunc > N - pos.top().index)
        {
            break;
        }
    }
    
   std::cout<<tempindex;
}
