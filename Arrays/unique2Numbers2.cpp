// Program to find the two non-repeating elements in an array of repeating elements/ Unique Numbers 2 

// Using bitwise XOR - xor = arr[0]^arr[1]^arr[2].....arr[n-1]
// Time Complexity: O(n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

//void get2NonRepeatingNos(vector<int> nums, int n, int *x, int *y){
void get2NonRepeatingNos(vector<int> nums, int n){
    int Xor = nums[0];

    int set_bit_no;
    int i;
    // *x = 0
    // *y = 0
    int x = 0;
    int y = 0;

    for(i=0; i<n; i++)
        Xor ^= nums[i];
    
    set_bit_no = Xor & ~(Xor-1);

    for(i=0; i<n; i++){
        if(nums[i] & set_bit_no)
            x ^= nums[i];       // *x ^= nums[i]
        else
            y ^= nums[i];       // *y ^= nums[i]
    }

    cout << "The two non-repeating elements are: " << x << " & " << y << endl;
}

int main(){
    vector<int> nums = { 2, 3, 7, 9, 11, 2, 3, 11 };
    int n = nums.size();
    //int *x = new int[(sizeof(int))];
    //int *y = new int[(sizeof(int))];
    //get2NonRepeatingNos(nums, n, x, y);
    get2NonRepeatingNos(nums, n);
    //cout << "The two non-repeating elements are: " << *x << " & " << *y << endl;

}

