// Program to print BFS traversal from a given vertex in a given graph 

// Using an adjacency list
// Time complexity: O(V + E) - Space Complexity: O(V)

// For both connected & disconnected graph

#include<bits/stdc++.h>
using namespace std;

class Graph {

public:
    map<int, bool> visited;
    map<int, list<int>> adj;


    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void BFSUtil(int v){

        list<int> queue;

        visited[v] = true;
        queue.push_back(v);

        while(!queue.empty()){
            v = queue.front();
            cout << v << " ";
            queue.pop_front();

            for(auto adjacent: adj[v]){
                if(!visited[adjacent]){
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
    }

    void BFS(int v){
        for(auto i:adj){
            if(visited[i.first] == false)
                BFSUtil(i.first);
        }
    }

};


int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 5);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    
    return 0;
}