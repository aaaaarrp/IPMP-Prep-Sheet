// Topological Sorting

// 


#include<bits/stdc++.h>
using namespace std;

class graph {

public:
    map<int, bool>visited;
    map<int, list<int>> adj;

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void SortUtil(int v, stack<int> &st){
        visited[v] = true;

        for(auto i=adj[v].begin(); i != adj[v].end(); i++){
            if(!visited[*i])
                SortUtil(*i, st);
        }

        st.push(v);
    }

    void topologicalSort(){
        stack<int> st;
        for(auto i:adj){
            if(visited[i.first] == false)
                SortUtil(i.first, st);
        }
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }

};

int main(){
    graph g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    g.topologicalSort();

 
    return 0;
}