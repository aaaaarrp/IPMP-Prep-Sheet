// Program to find maximum sum such that no two elements are adjacent

// Using Dynamin programming
// Time: O(n) - Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int> arr, int n){
    int sum[n][2];
    if(n == 1)
        return arr[0];
    sum[0][0] = 0;
    sum[0][1] = arr[0];

    for(int i=1; i<n; i++){
        sum[i][1] = sum[i-1][0]+arr[i];
        sum[i][0] = max(sum[i-1][0], sum[i-1][1]);
    }
    return max(sum[n-1][0], sum[n-1][1]);
}

int main(){
	vector<int> arr = { 5, 5, 10, 100, 10, 5 };

	cout << findMaxSum(arr, arr.size()) << endl;
	return 0;
}
