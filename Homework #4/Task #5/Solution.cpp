#include <iostream>
#include <stack>
#include <queue>
bool isvalid(std::queue<int> inc)
{
    std::stack<int> side;
    std::stack<int> out;
    int size = inc.size();
    for (int i = 1; i <= size && !inc.empty();)
    {
        if (inc.front() == i)
        {
            out.push(inc.front());
            inc.pop();
            i++;
        }
        else if (!side.empty() && side.top() == i)
        {
            out.push(side.top());
            side.pop();
            i++;
        }
        else
        {
            side.push(inc.front());
            inc.pop();
        }
    }

    while (!side.empty())
    {
        out.push(side.top());
        side.pop();
    }
    while (!out.empty())
    {
        int temp = out.top();
        out.pop();
        if (!out.empty())
        {
            if (temp <= out.top())
            {
                return false;
            }
            out.pop();
        }
        else
        {
            break;
        }
    }

    return true;
    
}
int main()
{
    std::queue<int> inc;
    std::queue<int> empty;
    int T;
    int N;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::cin >> N;
        for (int j = 0; j < N; j++)
        {
            int temp;
            std::cin >> temp;
            inc.push(temp);
        }

       if (isvalid(inc)) 
        {
            std::cout << "yes"<<std::endl;
        }
        else
        {
            std::cout << "no"<<std::endl;
        }
        inc = empty;
    }
}
