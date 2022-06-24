// Bellman Ford Algorithm : DP

// Time: O(VE)


#include<bits/stdc++.h>
using namespace std;

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Edge {
    int src, dest, weight;
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge [E];
    return graph;
}

void printSolution(int dist[], int n){
    cout << "Vertex  Distance from Source" << endl;
    for(int i=0; i<n; i++){
        cout << i << "\t\t" << dist[i] << endl;
    }
}

void BellmanFord(struct Graph* graph, int src){
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for(int i=0; i<V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for(int i=0; i<V; i++){
        for(int j=0; j<E; j++){
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int w = graph->edge[j].weight;
            if(dist[u] != INT_MAX && dist[u]+w < dist[v])
                dist[v] = dist[u]+w;
        }
    }

    for(int i=0; i<E; i++){
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int w = graph->edge[i].weight;
        if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
            cout << "Graph contains cycle!";
            return;
        }
    }

    printSolution(dist, V);
    return;
}

int main()
{
    int V = 5;
    int E = 8; 
    struct Graph* graph = createGraph(V, E);
 
    // edge 0-1 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // edge 0-2 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // edge 1-2
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // edge 1-3 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // edge 1-4 
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // edge 3-2 
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // edge 3-1 
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // edge 4-3 
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 
    BellmanFord(graph, 0);
 
    return 0;
}