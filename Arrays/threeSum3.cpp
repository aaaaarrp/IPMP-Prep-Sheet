
// Find a triplet that sum to a given value - Hashing-based solution : O(N^2)

#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int size, int target){
    for(int i=0; i<size-2; i++){
        unordered_set<int> s;
        int current_sum = target - A[i];
        for(int j=i+1; j<size; j++){
            if(s.find(current_sum - A[j]) != s.end()){
                cout <<  "  " << A[i]  << ", " << A[j] << ", " << current_sum - A[j] << " " << endl;
                return true;
            }
            s.insert(A[j]);
        }
    }
    return false;
}

int main(){
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    find3Numbers(A, arr_size, sum);
    return 0;
}