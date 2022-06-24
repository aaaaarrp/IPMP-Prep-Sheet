// Program to Stock Buy Sell to Maximize Profit

// Time Complexity: O(n) - Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> price, int n){
    int profit = 0;
    for(int i=1; i<n; i++){
        if(price[i] > price[i-1])
            profit += price[i] - price[i-1];
    }
    return profit;
}

int main()
{
    vector<int> price = { 20, 10, 30, 60, 40, 90 };
    cout << maxProfit(price, price.size()) << endl;
  
    return 0;
}