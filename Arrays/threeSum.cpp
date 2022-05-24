
// Find a triplet that sum to a given value - Naive approach : O(n3) 

#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int size, int target){
    for(int i=0; i < size-2; i++){
        for(int j=i+1; j < size-1; j++){
            for(int k=j+1; k < size; k++){
                if(A[i]+A[j]+A[k] == target){
                    cout <<  "  " << A[i]  << " " << A[j] << " " << A[k] << " " << endl;
                    return true;
                }
            }
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