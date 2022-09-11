#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <climits>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest, weight;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors of `Edge` to represent an adjacency list
    vector<vector<Edge>> adjList;
 
    // Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type vector<Edge>
        adjList.resize(n);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
 
            adjList[src].push_back({src, dest, weight});
            adjList[dest].push_back({dest, src, weight});
        }
    }
};
 
// A BFS Node
struct Node
{
    // current vertex number and cost of the current path
    int vertex, weight;
 
    // set of nodes visited so far in the current path
    set<int> s;
};
 
// Perform BFS on graph `graph` starting from vertex `v`
int findMaxCost(Graph const &graph, int src, int k)
{
    // create a queue for doing BFS
    queue<Node> q;
 
    // add source vertex to set and enqueue it
    set<int> vertices;
    vertices.insert(src);
    q.push({src, 0, vertices});
 
    // stores maximum cost of a path from the source
    int maxCost = INT_MIN;
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        Node node = q.front();
        q.pop();
 
        int v = node.vertex;
        int cost = node.weight;
        vertices = node.s;
 
        // if the destination is reached and BFS depth is equal to `m`,
        // update the minimum cost calculated so far
        if (cost > k) {
            maxCost = max(maxCost, cost);
        }
 
        // do for every adjacent edge of `v`
        for (Edge edge: graph.adjList[v])
        {
            // check for a cycle
            if (vertices.find(edge.dest) == vertices.end())
            {
                // add current node to the path
                set<int> s = vertices;
                s.insert(edge.dest);
 
                // push every vertex (discovered or undiscovered) into
                // the queue with a cost equal to the
                // parent's cost plus the current edge's weight
                q.push({edge.dest, cost + edge.weight, s});
            }
        }
    }
 
    // return max-cost
    return maxCost;
}
 
int main()
{
    // vector of graph edges as per the above diagram
    
    int n, M;cin>>n>>M;
    vector<Edge> edges;
    for(int i=0; i<M; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Edge(u, v, wt));
    }
    // total number of nodes in the graph (labelled from 0 to 7)
 
    // build a graph from the given edges
    Graph graph(edges, n);
 
    int src = 0;
    int cost = 50;
 
    // Start modified BFS traversal from source vertex `src`
    int maxCost = findMaxCost(graph, src, cost);
 
    if (maxCost != INT_MIN) {
        cout << maxCost;
    }
    else {
        cout << "All paths from source have their costs < " << cost;
    }
 
    return 0;
}