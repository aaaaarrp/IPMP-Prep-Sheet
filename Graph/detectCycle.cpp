// Program to Detect Cycle in a Directed/Undirected Graph

// Time complexity: O(V + E) - Space Complexity: O(V)

#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    map<int, bool> recStack;

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool isCyclicUtil(int v){
        if(visited[v] == false){
            visited[v] = true;
            recStack[v] = true;

            for(auto i = adj[v].begin(); i != adj[v].end(); i++){
                if(!visited[*i] && isCyclicUtil(*i))
                    return true;
                else if(recStack[*i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }

    bool isCyclic(){
        for(auto i:adj){
            visited[i.first] = false;
            recStack[i.first] = false;
        }
        for(auto i:adj){
            if(isCyclicUtil(i.first))
                return true;
        }
        return false;
    }
};

int main(){
    graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    //g.addEdge(7, 6);

    if(g.isCyclic())
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph doesn't contain cycle" << endl;
    return 0;
}