// Floyd Warshall Algorithm

// Time Complexity: O(V^3) - Auxiliary Space: O(V^2)

#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define V 4

void printSolution(int dist[][V]){
    cout << "Shortest distances between every pair of vertices:" << endl;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][V]){
    int dist[V][V], i, j, k;
    
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            dist[i][j] = graph[i][j];
        }
    }

    for(k=0; k<V; k++){
        for(i=0; i<V; i++){
            for(j=0; j<V; j++){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }

    printSolution(dist);
}


int main()
{
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    floydWarshall(graph);
    return 0;
}