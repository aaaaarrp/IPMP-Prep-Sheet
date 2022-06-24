// Program to find the two non-repeating elements in an array of repeating elements/ Unique Numbers 2 

// Using Maps
// Time Complexity: O(nlogn) - Auxiliary Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void get2NonRepeatingNos(vector<int> nums, int size){
    map<int, int> hash;

    for(int i=0; i<size; i++)
        hash[nums[i]]++;

    cout << "The non-repeating elements are: ";

    for(auto i : hash){
        if(i.second == 1)
            cout << i.first << " ";
    }

    cout << endl;
}

int main(){
    vector<int> nums= { 2, 3, 7, 9, 11, 2, 3, 11 };
    int n = nums.size();
    get2NonRepeatingNos(nums, n);
}