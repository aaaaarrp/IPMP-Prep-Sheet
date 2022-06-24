// Program to find maximum sum such that no two elements are adjacent

// Modified first method to optimize space
// Time: O(n) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int> arr, int n){
    int included = arr[0];
    int excluded = 0;
    int excluded_new;
    for(int i= 1; i<n; i++){
        excluded_new = max(included, excluded);
        included = arr[i] + excluded;
        excluded = excluded_new;
    }
    return max(included, excluded);
}

int main(){
	vector<int> arr = { 5, 5, 10, 100, 10, 5 };

	cout << findMaxSum(arr, arr.size()) << endl;
	return 0;
}
