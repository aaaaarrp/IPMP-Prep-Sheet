// Program to Find if there is a path between two vertices in a directed graph

// Using BFS
// Time complexity: O(V+E) - Space Complexity: O(V)

#include<bits/stdc++.h>
using namespace std;

class graph {

public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool isReachable(int u, int v){
        if(u == v)
            return true;

        list<int> queue;
        visited[u] = true;
        queue.push_back(u);

        while(!queue.empty()){
            u = queue.front();
            queue.pop_front();

            for(auto adjacent: adj[u]){
                if(adjacent == v)
                    return true;
                if(!visited[adjacent]){
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
        return false;
    }

};

int main(){
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int u = 3;
    int v = 2;

    if(g.isReachable(u, v))
        cout<< "There is a path from " << u << " to " << v << endl;
    else
        cout<< "There is no path from " << u << " to " << v << endl;

    return 0;
}