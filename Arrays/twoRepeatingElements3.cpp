// Program to Find the two repeating elements in a given array

// By making two equations
// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    return (n==0) ? 1 : n*fact(n-1);
}

void getTwoRepeatingElements(vector<int> nums, int size){
    int S = 0;
    int P = 1;
    int D;     

    int x, y, i;
    int n = size-2;

    for(int i=0; i<size; i++){
        S = S+nums[i];
        P = P*nums[i];
    }

    S = S - n*(n+1)/2;      // S = x+y
    P = P/fact(n);           // P = x*y

    D = sqrt(S*S - 4*P);     // D = x - y

    x = (D+S)/2;
    y = (S-D)/2;

    cout << "Two Repeating elements are: " << x << " & " << y << endl;

}


int main(){
    vector<int> nums = {4, 2, 4, 5, 2, 3, 1};
    getTwoRepeatingElements(nums, nums.size());
}