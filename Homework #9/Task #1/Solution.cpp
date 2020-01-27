#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;
class DisjointSet
{
    unordered_map<int, int> parent;
    int currentLast = 0;
public:
    void initialize(int size)
    {
        for (int i = 0; i < size; i++)
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
    list<Pair> adjacent;
    bool used = false;
    
    bool hasNeighbour(int index)
    {
        for (auto neighbour : adjacent)
        {
            if (neighbour.index == index)
            {
                return true;
            }
        }
        return false;
    }
    
    void addNeighbour(int index, int weight)
    {

        adjacent.push_back(Pair{index, weight});

    }
};

class Graph
{
    vector<Node> nodes;
    
public:
    Graph(int size = 0)
    {
        nodes.resize(size);
    }
    
    void connect(int from, int to, int weight)
    {
        nodes[from].addNeighbour(to, weight);
        nodes[to].addNeighbour(from, weight);
    }
    
    vector<Edge> getAllEdges()
    {
        vector<Edge> edges;
        for (int from = 0; from < nodes.size(); from++)
        {
            for (auto neighbours : nodes[from].adjacent)
            {
                int to = neighbours.index;
                int weight = neighbours.weight;
                edges.push_back(Edge{from, to, weight});
            }
        }
        return edges;
    }
    int Kruskal()
    {
        vector<Edge> edges = getAllEdges();
        sort(edges.begin(), edges.end());
        
        DisjointSet comps;
        comps.initialize(nodes.size());
        int weight = 0;
        for (Edge edge : edges)
        {
            if (comps.find(edge.from) != comps.find(edge.to))
            {
                weight += edge.weight;
                comps.unite(edge.from, edge.to);
            }
        }
        return weight;
    }
    
    
};

int main() {
    int N,M;
    cin>>N>>M;
    Graph G(N);
    int a,b,c;
    for (int i = 0; i < M; i++)
    {
        cin>>a>>b>>c;
        G.connect(a,b,c);
    }
    
    std::cout<<G.Kruskal();
    return 0;
}
