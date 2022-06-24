// Program to Find the maximum repeating number

// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int maxRepeating(vector<int> &arr, int n, int k){
    for(int i = 0; i<n; i++){
        arr[arr[i%k]] += k;
    }

    int max = arr[0];
    int result = 0;
    
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
            result = i;
        }
    }
    return result;

    /* To get the original array back
    for (int i = 0; i< n; i++)
        arr[i] = arr[i]%k;
    */

}

int main()
{
    vector<int> arr = {2, 3, 3, 5, 3, 4, 1, 7};
    int k = 8;
    cout << "The maximum repeating number is " << maxRepeating(arr, arr.size(), k) << endl;
 
    return 0;
}