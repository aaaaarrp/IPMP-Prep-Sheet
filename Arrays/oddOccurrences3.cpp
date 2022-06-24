// Find the two numbers with odd occurrences in an unsorted array

// Using bitwise XOR
// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void getOddOccurrences(vector<int> nums, int n){
    int Xor = nums[0];

    int set_bit_no;
    int i;
    int x = 0;
    int y = 0;

    for(i = 1; i < n; i++)
        Xor ^= nums[i];
    
    set_bit_no = Xor & ~(Xor-1);

    for(i = 0; i < n; i++){
        if(nums[i] & set_bit_no)
            x ^= nums[i];
        else
            y ^= nums[i];
    }

    cout << "Two Odd elements are: " << x << " & " << y << endl;
}

int main(){
    vector<int> nums = {4, 2, 4, 5, 2, 3, 3, 1};
    getOddOccurrences(nums, nums.size());
}