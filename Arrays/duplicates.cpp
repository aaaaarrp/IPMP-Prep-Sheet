// Program to find duplicates in O(n) time


#include <bits/stdc++.h>
using namespace std;

void duplicates(vector<int> &nums, int n){
    for(int i=0; i<n; i++){
        int position = nums[i]%n;
        nums[position] = nums[position]+n;
    }

    for(int i=0; i<n; i++){
        if(nums[i] >= n*2)
            cout << i << " ";
    }
    cout << endl;
}

int main()
{
	vector<int> nums = { 0, 4, 3, 2, 7, 8, 2, 3, 4 };
    duplicates(nums, nums.size());
	return 0;
}
