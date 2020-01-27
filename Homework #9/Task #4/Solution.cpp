#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_map>

class DisjointSet
{
    std::unordered_map<int, int> parent;
    int currentLast = 1;
public:
    DisjointSet(int size)
    {
        for (int i = 1; i <= size; i++)
        {
            add(i);
        }
    }
    
    void add(int child)
    {
        parent[child] = currentLast;
        currentLast++;
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
        parent[aRoot] = bRoot;
    }
};

struct Pair
{
    int index;
    int weight;
};
struct Edge
{
    int from;
    int to;
    int weight;
    
    bool operator<(Edge& rhs)
    {
        return weight < rhs.weight;
    }
};

struct Node
{
    std::list<Pair> neighbours;
    
    void addNeighbour(int to, int weight)
    {
        neighbours.push_back(Pair{to, weight});
    }
    
    bool hasNeighbour(int index)
    {
        for (auto neighbour : neighbours)
        {
            if (neighbour.index == index)
            {
                return true;
            }
        }
        return false;
    }
};
class Graph
{
    std::vector<Node> nodes;
public:
    Graph(int size = 0)
    {
        nodes.resize(size + 1);
    }
    
    void connect(int from, int to, int weight)
    {
        nodes[from].addNeighbour(to, weight);
    }
    
    std::vector<Edge> getAllEdges()
    {
        std::vector<Edge> edgeList;
        for (int i = 1; i < nodes.size(); i++)
        {
            for (auto neighbour : nodes[i].neighbours)
            {
                edgeList.push_back(Edge{i, neighbour.index, neighbour.weight});
            }
        }
        return edgeList;
    }
    
    int Kruskal()
    {
        int totalWeight = 0;
        std::vector<Edge> edgeList = getAllEdges();
        std::sort(edgeList.begin(), edgeList.end());
        
        DisjointSet comps(nodes.size());
        for (Edge edge : edgeList)
        {
            if (comps.find(edge.from) != comps.find(edge.to))
            {
                totalWeight += edge.weight;
                comps.unite(edge.from, edge.to);
            }
        }
        
        return totalWeight;
    }
};

int main()
{
    int n,m;
    scanf("%i", &n);
    scanf("%i", &m);
    Graph g(n);
    int a,b,w;
    for (int i = 0; i < m; i++)
    {
        scanf("%i", &a);
        scanf("%i", &b);
        scanf("%i", &w);
        
        g.connect(a, b, w);
    }
    
    int result = g.Kruskal();
    printf("%i", result);
}
