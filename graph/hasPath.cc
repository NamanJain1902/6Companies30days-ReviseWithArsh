#include<bits/stdc++.h>
using namespace std;

class Edge {
  public:
  
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt){
     this->src = src;
     this->nbr = nbr;
     this->wt = wt;
  }
  Edge() {};
};

class Graph
{
    int V;
    int E;

    public:
    vector<vector<Edge>> adjList;
    Graph(vector<Edge> &edges, int N){
        this->V = N;
        adjList.resize(N);
        for(Edge &edge: edges){
            adjList[edge.src].push_back(edge);
            // adjList[edge.nbr].push_back(edge);
        }
    }
    // Graph(int v, int e){
    //     this->V = v;
    //     this->E = e;
    // }
    vector<vector<Edge>> getadjList(){
        return adjList;
    }
    void print(){
        for(int i=0; i<V;++i){
            cout << "
Vertex " << i << " = ";
            for(auto edge : adjList[i]){
                cout << edge.src << " " << edge.nbr<< " " << edge.wt << " --> ";
            }
            puts("");
        }
    }
};

bool hasPath(vector<vector<Edge>> &adjList, int src, int dest, vector<bool> &discovered){
    if(src == dest){
        return true;
    }  
    discovered[src] = true; 
    for(Edge edge : adjList[src]){
        if(!discovered[edge.nbr]){
            bool hasNbrPath = hasPath(adjList, edge.nbr, dest, discovered);
            if(hasNbrPath){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int V,E;
    cin >> V >> E;

    vector<vector<Edge>> graph(V);
    vector<Edge> edges;
    for(int i=0; i<E; ++i){
        int src;
        int dest;
        int wt;

        cin >> src>>dest>>wt;
        Edge obj1(src, dest, wt);
        Edge obj2(dest, src, wt);
        edges.push_back(obj1);
        edges.push_back(obj2);
        
        // graph[src].push_back(obj1);
        // graph[dest].push_back(obj2);
    }
    vector<bool> discovered(V, false);
    Graph obj(edges, V);
    // obj.print();
    // for(int i=0; i<V; ++i){
        // if(!discovered[i]){
        // }
    // }
    vector<vector<Edge>> r = obj.getadjList();
    cout <<( hasPath(r, 0, 6, discovered) == 1 ? "true" : "false") << endl;
    return 0;   
}
