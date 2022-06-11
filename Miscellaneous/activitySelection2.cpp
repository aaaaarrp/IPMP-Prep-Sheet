// Program for activity selection problem.

// Greedy Method
// Time: Activities are not sorted -> O(nlogn)
// Time: Activities are sorted -> O(n) 

#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool compareActivity(Activity a1, Activity a2){
    return (a1.finish < a2.finish);
}

void printMaxActivities(Activity arr[], int n){
    sort(arr, arr+n, compareActivity);
    cout << "Following activites are selected: ";
    int i = 0;
    cout << "(" << arr[i].start << "," << arr[i].finish << ")" << " ";
    for(int j=1; j<n; j++){
        if(arr[j].start >= arr[i].finish){
            cout << "(" << arr[j].start << "," << arr[j].finish << ")" << " ";
            i = j;
        }
    }
    cout << endl;
}
int main(){
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    Activity arr2[] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    printMaxActivities(arr, n);
    printMaxActivities(arr2, n2);
    return 0;
}