
// Approximate Algorithm for Vertex Cover : Time O(V + E)

#include <bits/stdc++.h>
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void printVertexCover();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::printVertexCover()
{
    // Initialize all vertices as not visited.
    bool visited[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    list<int>::iterator i;

    // Consider all edges one by one
    for(int u=0; u < V; u++){
        // An edge is only picked when both visited[u] and visited[v] are false
        if(visited[u] == false){
            // Go through all adjacents of u and pick the first not
            // yet visited vertex (We are basically picking an edge
            // (u, v) from remaining edges.
            for(i = adj[u].begin(); i != adj[u].end(); ++i){
                int v = *i;
                if(visited[v] == false){
                    visited[v] = true;
                    visited[u] = true;
                    break;
                }
            }
        }
    }

    for(int i=0; i<V; i++){
        if(visited[i])
            cout << i << " ";
    }
}


int main(){

    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);

    g.printVertexCover();

    return 0;
}