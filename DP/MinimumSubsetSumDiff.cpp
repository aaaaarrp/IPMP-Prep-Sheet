// Program to Partition a set into two subsets such that the difference of subset sums is minimum

// Variation of 0/1 Knapsack 
// Bottom up approach -> Time: O(n^2)

#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(int n, vector<int> &arr){
    int range = 0;
    for(auto i:arr)
        range += i;     // total sum

    vector<vector<int>> table(n+1, vector<int> (range+1));  // finding subset sum
    for(int i=0; i<n+1; i++)
        table[i][0] = 1;
    for(int j=1; j<range+1; j++)
        table[0][j] = 0;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<range+1; j++){
            if(arr[i-1] <= j)
                table[i][j] = table[i-1][j-arr[i-1]] || table[i-1][j];
            else
                table[i][j] = table[i-1][j];
        }
    }

    /*  
        iterate in table vector from the mid and return the first true value (S1)
        Here S2 - S1 should be minimized
        Minimized value = S2 - S1
        Range is total sum
        S2 = Range - S1 => Range - S1 - S1 => Range - 2*S1
    */

    int res;               
    for(int i=range/2; i>=0; i--){    
        if (table[n][i] == 1){        
            res = range - 2 * i;      
            break;         
        }
    }

    return res;

}

int main()
{
    vector<int> arr = {1, 6, 11, 5};
    cout << "Minimum difference: " << minSubsetSumDiff(arr.size(), arr) << endl;
}