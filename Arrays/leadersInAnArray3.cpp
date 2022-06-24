// Program to Print the elements greater than all the elements to its right

// Modified second method to get the output in order
// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void printLeaders(vector<int> arr, int n){
    vector<int> leaders;
    int max = arr[n-1];
    leaders.push_back(max);

    for(int i = n-2; i >= 0; i--){
        if(arr[i] > max){
            max = arr[i];
            leaders.push_back(max);
        }
    }

    for(int i=leaders.size()-1; i>= 0; i--)
        cout << leaders[i] << " ";
    cout << endl;
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    printLeaders(arr, arr.size());
    return 0;
}