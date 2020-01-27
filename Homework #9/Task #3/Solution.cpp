#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class DisjointSet
{
    unordered_map<int, int> parent;
    int currentLast = 1;
public:
    DisjointSet(int size = 0)
    {
        for (int i = 1; i <= size; i++)
        {
            add(i);
        }
    }
    
    int find(int child)
    {
        if (parent[child] == child)
        {
            return child;
        }
        
        int root = find(parent[child]);
        parent[child] = root;
        return root;
    }
    
    void unite(int a, int b)
    {
        int aRoot = find(a);
        int bRoot = find(b);
        parent[bRoot] = aRoot;
    }
    
    void add(int child)
    {
        parent[child] = currentLast;
        currentLast++;
    }
};

int main()
{
    int n,m;
    scanf("%i", &n);
    scanf("%i", &m);
    int a,b;
    DisjointSet set(n);
    for (int i = 0; i < m; i++)
    {
        scanf("%i", &a);
        scanf("%i", &b);
        set.unite(a, b);
    }
    int q;
    int x;
    scanf("%i", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%i", &x);
        scanf("%i", &a);
        scanf("%i", &b);
        x--;
        if (x)
        {
            set.unite(a, b);
        }
        else
        {
            if (set.find(a) == set.find(b))
            {
                cout<<1;
            }
            else cout<<0;
        }
    }

}
