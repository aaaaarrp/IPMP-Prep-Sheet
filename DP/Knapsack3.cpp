
// A dynamic programming based solution for 0-1 Knapsack problem  - Space optimized

    // We know we are always using the the current row or
    // the previous row of the array/vector . Thereby we can
    // improve it further by using a 2D array but with only
    // 2 rows i%2 will be giving the index inside the bounds
    // of 2d array K

// Time O(N*W) : Space O(2*W)


#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int value[], int weight[], int W, int n){
    int i, w;
    int K[2][W+1];

    for(i=0; i <= n; i++){
        for(w=0; w <= W; w++){
            if( i == 0 || w == 0)
                K[i%2][w] = 0;
            else if(weight[i-1] <= w)
                K[i%2][w] = maximum(value[i-1]+K[(i-1)%2][w - weight[i-1]], K[(i-1)%2][w]);
            else
                K[i%2][w] = K[(i-1)%2][w];
        }
    }
    return K[n%2][W];

}

int main(){
    int value[] = { 60, 100, 120};
    int weight[] = { 10, 20, 30}; 
    int w = 50;
    int size = sizeof(value)/sizeof(value[0]);
    cout << knapsack(value, weight, w, size);
}