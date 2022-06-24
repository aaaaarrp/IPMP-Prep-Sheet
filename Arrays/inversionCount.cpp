// Program to Count Inversions in an array

// Time: O(n^2) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int countInversion(vector<int> arr, int n){
    int count=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,20,6,4,5};
    cout << countInversion(arr, arr.size()) << endl;
    return 0;

}