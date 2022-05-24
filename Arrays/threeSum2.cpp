
// Find a triplet that sum to a given value - Sorting & two pointer approach : O(N^2)

#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int size, int target){
    int left, right;
    sort(A, A+size);

    for(int i=0; i < size-2; i++){
        left = i+1;
        right = size-1;

        while(left < right){
            if(A[i] + A[left] + A[right] == target){
                cout <<  "  " << A[i]  << ", " << A[left] << ", " << A[right] << " " << endl;
                return true;
            }
            if(A[i]+A[left]+A[right] > target)
                right--;
            else 
                left++;
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