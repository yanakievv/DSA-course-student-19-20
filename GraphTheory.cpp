#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <climits>
int temp = 0;

class DisjointSet
{
	std::unordered_map<int, int> parent;
	int currentMin = 0;

public:
	DisjointSet(int size = 0)
	{
		for (int i = 0; i < size; i++)
		{
			add(i);
		}
	}

	void add(int child)
	{
		parent[child] = currentMin;
		currentMin++;
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
	int distance;

	bool operator<(const Pair& rhs) const
	{
		return distance < rhs.distance;
	}
};
struct Edge
{
	int from;
	int to;
	int weight;

	bool operator<(const Edge& rhs) const
	{
		return weight < rhs.weight;
	}
};
struct Node
{
	std::list<Pair> neighbours;

	bool hasNeighbour(int index)
	{
		for (auto i : neighbours)
		{
			if (i.index == index)
			{
				return true;
			}
		}
		return false;
	}
	void addNeighbour(int index, int distance)
	{
		neighbours.push_back(Pair{ index, distance });
	}
};
class Graph
{
	std::vector<Node> nodes;

	void _topSort(std::list<int>& sorted, std::vector<char>& visited, int start)
	{
		visited[start] = 'o';
		for (auto neighbour : nodes[start].neighbours)
		{
			if (visited[neighbour.index] == 'u')
			{
				_topSort(sorted, visited, neighbour.index);
			}
			else if (visited[neighbour.index] == 'o')
			{
				std::cout << "Cycle formed" << std::endl;
			}
		}
		visited[start] = 'c';
		sorted.push_front(start);
	}

public:
	Graph(int size = 0)
	{
		nodes.resize(size);
	}
	Graph(const Graph& rhs)
	{
		nodes = rhs.nodes;
	}
	Graph& operator=(const Graph& rhs)
	{
		if (this != &rhs && &rhs != nullptr)
		{
			nodes = rhs.nodes;
		}
		return *this;
	}

	void print() const 
	{
		for (int node = 0; node < nodes.size(); node++) 
		{
			std::cout << node << ": ";

			for (auto neighbour : nodes[node].neighbours) 
			{
				std::cout << neighbour.index << "(" << neighbour.distance << "), ";
			}
			std::cout << "\n";
		}
	}
	std::vector<Edge> getAllEdges()
	{
		std::vector<Edge> edges;
		for (int from = 0; from < nodes.size(); from++)
		{
			for (auto it : nodes[from].neighbours)
			{
				int to = it.index;
				int weight = it.distance;
				if (from < to)
				{
					edges.push_back(Edge{ from, to, weight });
				}
			}
		}

		return edges;
	}

	void connect(int from, int to, int distance = 0) //dont put third argument when connecting nodes to make it unweighted
	{
		if (!nodes[from].hasNeighbour(to)) // remove to make it multigraph
		{
			nodes[from].addNeighbour(to, distance);
			//nodes[to].addNeighbour(from, distance); remove to make graph undirected
		}
	}

	void DFS(int start, int goal)
	{
		if (nodes.size() < 1)
		{
			return;
		}

		std::vector<bool> visited(nodes.size(), false);
		std::vector<int> parent(nodes.size(), -1);

		std::stack<Pair> nextToProcess;
		nextToProcess.push(Pair{ start, 0 });

		while (!nextToProcess.empty())
		{
			Pair currentPair = nextToProcess.top();
			nextToProcess.pop();
			int currentIndex = currentPair.index;
			if (visited[currentIndex])
			{
				continue;
			}
			visited[currentIndex] = true;
			for (auto neighbour : nodes[currentIndex].neighbours)
			{
				parent[neighbour.index] = currentIndex;
				if (visited[neighbour.index])
				{
					continue;
				}
				nextToProcess.push(neighbour);
			}
		}

		while (start != goal)
		{
			std::cout << start << " ";
			start = parent[start];
		}
		std::cout << goal;
	}
	void BFS(int start, int goal)
	{
		if (nodes.size() < 1)
		{
			return;
		}

		std::vector<bool> visited(nodes.size(), false);
		std::vector<int> parent(nodes.size(), -1);

		std::queue<Pair> nextToProcess;
		nextToProcess.push(Pair{ start, 0 });

		while (!nextToProcess.empty())
		{
			Pair currentPair = nextToProcess.front();
			nextToProcess.pop();
			int currentIndex = currentPair.index;
			if (visited[currentIndex])
			{
				continue;
			}
			visited[currentIndex] = true;

			for (auto neighbour : nodes[currentIndex].neighbours)
			{
				if (visited[neighbour.index])
				{
					continue;
				}
				parent[neighbour.index] = currentIndex;
				nextToProcess.push(neighbour);
			}
		}

		while (parent[goal] != -1)
		{
			std::cout << goal << " ";
			goal = parent[goal];
		}
	}

	std::vector<int> Dijkstra(int start)
	{
		if (nodes.size() < 1)
		{
			return std::vector<int>();
		}

		std::vector<bool> visited(nodes.size(), false);
		std::vector<int> distance(nodes.size(), INT_MAX);
		std::vector<int> parent(nodes.size(), -1);

		std::priority_queue<Pair> nextToProcess;
		distance[start] = 0;
		nextToProcess.push(Pair{ start, 0 });

		while (!nextToProcess.empty())
		{
			Pair currentPair = nextToProcess.top();
			nextToProcess.pop();
			int currentIndex = currentPair.index;

			if (visited[currentIndex])
			{
				continue;
			}
			visited[currentIndex] = true;

			for (auto neighbour : nodes[currentIndex].neighbours)
			{
				int altDistance = distance[currentIndex] + neighbour.distance;
				if (altDistance < distance[neighbour.index])
				{
					distance[neighbour.index] = altDistance;
					parent[neighbour.index] = currentIndex;
					nextToProcess.push(neighbour); 
				}
			}
		}

		

		return distance;
	}

	Graph MST()
	{
		std::vector<Edge> edgeVect = getAllEdges();
		Graph Kruskals(nodes.size());
		DisjointSet set(nodes.size());
		std::sort(edgeVect.begin(), edgeVect.end());
		for (Edge edge : edgeVect)
		{
			if (set.find(edge.from) != set.find(edge.to))
			{
				set.unite(edge.from, edge.to);
				Kruskals.connect(edge.from, edge.to, edge.weight);
			}
		}

		return Kruskals;
	}

	std::list<int> topSort()
	{
		std::list<int> sorted;
		std::vector<char> visited(nodes.size(), 'u');

		for (int i = 0; i < nodes.size(); i++)
		{
			if (visited[i] == 'u')
			{
				_topSort(sorted, visited, i);
			}
		}
		return sorted;
	}
};

int main()
{
	Graph g(6);
	g.connect(0, 2, 3);
	g.connect(2, 4, 7);
	g.connect(0, 3, 2);
	g.connect(3, 4, 4);
	g.connect(2, 5, 14);
	g.connect(4, 5, 8);
	g.connect(5, 0, 10);

	Graph Kruskal(g.MST());

	g.print();

	/*std::vector<int> Dijkstra = g.Dijkstra(temp);
	for (int i = 0; i < Dijkstra.size(); i++)
	{
		if (Dijkstra[i] == INT_MAX)
		{
			continue;
		}
		std::cout << "Distance from " << temp << " to " << i << " is " << Dijkstra[i] << std::endl;
	}*/

	std::list<int> sorted = Kruskal.topSort();

	for (auto i : sorted) {

		std::cout << i << " ";

	}

	std::cout << "\n";


}