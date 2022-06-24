// Program to Stock Buy Sell to Maximize Profit

// Time Complexity: O(n2) - Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> price, int start, int end){
    if (end <= start)
        return 0;

    int profit = 0;

    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (price[j] > price[i]) {
                int curr_profit = price[j] - price[i]
                                  + maxProfit(price, start, i - 1)
                                  + maxProfit(price, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

int main()
{
    vector<int> price = { 20, 10, 30, 60, 40, 90 };
    cout << maxProfit(price, 0, price.size() - 1) << endl;
  
    return 0;
}