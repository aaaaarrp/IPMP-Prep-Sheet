// Program to Stock Buy Sell to Maximize Profit

// Time Complexity: O(n) - Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void maxProfit(vector<int> price, int n){
    if(n == 1)
        return;
    int i=0;
    while(i < n-1){
        while(i < n-1 && price[i+1] <= price[i])
            i++;
        if(i == n-1)
            break;
        int buy = i++;
        while(i < n && price[i] >= price[i-1])
            i++;
        int sell = i-1;
        cout << "Buy on day " << buy << " & Sell on day " << sell << endl;
    }
}

int main()
{
    vector<int> price = { 20, 10, 30, 60, 40, 90 };
    maxProfit(price, price.size());
  
    return 0;
}