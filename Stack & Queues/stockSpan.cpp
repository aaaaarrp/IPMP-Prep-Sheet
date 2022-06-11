// The Stock Span Problem

// Brute force
// Time: O(n^2)

#include<bits/stdc++.h>
using namespace std;

void calculateSpan(vector<int> price, int n, vector<int> &span){
    span[0] = 1;
    for(int i=1; i<n; i++){
        span[i] = 1;
        for(int j=i-1; (j >= 0) && (price[i] >= price[j]); j--){
            span[i]++;
        }
    }
    for(int i=0; i<n; i++)
        cout << span[i] << " ";
    cout << endl;
}

int main(){
    vector<int> price = { 10, 4, 5, 90, 120, 80 };
    vector<int> span(price.size());
    calculateSpan(price, price.size(), span);
    return 0;
}