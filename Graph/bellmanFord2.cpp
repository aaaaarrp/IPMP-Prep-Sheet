
// Bellman Ford Algorithm (Dynamic Programming Implementation) : Time 

#include <bits/stdc++.h>
using namespace std;

// a structure to represent a weighted edge in graph
struct  edge{
    int source, destination, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph{
    int V, E;
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
};

// A utility function used to print the solution
void print(int distance[], int n){
    
}
