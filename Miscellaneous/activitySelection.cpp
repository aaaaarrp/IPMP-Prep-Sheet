// Program for activity selection problem.

// Greedy Method
// The following implementation assumes that the activities are already sorted according to their finish time

#include<bits/stdc++.h>
using namespace std;

void printMaxActivities(vector<int> start, vector<int> finish, int n){
    cout << "Following activities are slected: " << endl;
    int i, j;
    i = 0;
    cout << i << " ";
    for(j=1; j<n; j++){
        if(start[j] >= finish[i]){
            cout << j << " ";
            i = j;
        }      
    }
    cout << endl;
}
int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    int n = start.size();

    printMaxActivities(start, finish, n);
    return 0;
}