// C++ code to find Two elements whose sum is closest to zero
// Brute Force - O(n^2)

#include <bits/stdc++.h>
using namespace std;

void minAbsSumPair(int A[], int size){
    int l, r, sum, min_l, min_r, min_sum;
    if(size < 2)
        return;
    
    min_l = 0;
    min_r = 1;
    min_sum = A[0] + A[1];

    for(l=0; l < size-1; l++){
        for(r=l+1; r < size; r++){
            sum = A[l] + A[r];
            if(abs(min_sum) > abs(sum)){
                min_sum = sum;
                min_l = l;
                min_r = r;
            }
        }
    }

    cout << "The two elements whose sum is minimum are " << A[min_l] << " & " << A[min_r] << endl;
    
}

int main()
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    minAbsSumPair(arr, 6);
    return 0;
}
