// Program to Find the two repeating elements in a given array

// Using XOR
// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void getTwoRepeatingElements(vector<int> nums, int size){
    int Xor = nums[0];
    int set_bit_no;
    int x = 0;
    int y = 0;
    int i;
    int n = size-2;

    for(i=0; i<size; i++)
        Xor ^= nums[i];
    
    for(i=0; i<=n; i++)
        Xor ^= i;

    set_bit_no = Xor & ~(Xor-1);

    for(i=0; i<size; i++){
        if(nums[i] & set_bit_no)
            x ^= nums[i];
        else
            y ^= nums[i];
    }

    for(i=0; i<=n; i++){
        if(i & set_bit_no)
            x ^= i;
        else
            y ^= i;
    }

    cout << "The two repeating elements are: " << x << " & " << y << endl;

}

int main(){
    vector<int> nums = {4, 2, 4, 5, 2, 3, 1};
    getTwoRepeatingElements(nums, nums.size());
}