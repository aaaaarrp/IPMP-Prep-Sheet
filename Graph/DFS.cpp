// Program to print DFS traversal from a given vertex in a given graph 

// Using an adjacency list
// Time complexity: O(V + E) - Space Complexity: O(V)

// For both connected & disconnected graph


#include<bits/stdc++.h>
using namespace std;

class graph {

public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void DFSUtill(int v){
        visited[v] = true;
        cout << v << " ";

        for(auto i = adj[v].begin(); i != adj[v].end();i++){
            if(!visited[*i])
                DFSUtill(*i);
        }
    }

    void DFS(int v){
        for(auto i:adj){
            if(visited[i.first] == false)
                DFSUtill(i.first);
        }
    }

};

int main(){
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 5);
 
    cout << "Following is Depth First Traversal - \n"
            "(starting from vertex 2): ";
    g.DFS(2);

 
    return 0;
}