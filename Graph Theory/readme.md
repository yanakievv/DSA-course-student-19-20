# Graph Algorithms
Graph is represented using adjacency list.

Public functions: 

- void connectNodes(int from, int to, int distance = 0) // could change function definition to make undirected/directed (multi)graph. 
- void print() 
- vector<Edge> getAllEdges() //where an Edge is defined by {int from, int to, int distance} 
- void BFS(int start, int target)/DFS(int start, int target) // path gets printed after algorithm has found target 
- vector<int> Dijkstra(int start) // returns a vector of all distances between start and reachable nodes 
- Graph MST() // returns a minimal spanning tree of the graph that called the function 
- list<int> topSort() // returns the nodes of a directed acyclic graph in topological order 
