// The Stock Span Problem

// Linear time complexity solution without using stack
// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void calculateSpan(vector<int> price, int n, vector<int> &span){
    span[0] = 1;
    for(int i=1; i<n; i++){
        int counter=1;
        while((i-counter) >= 0 && price[i] >= price[i-counter])
            counter += span[i-counter];
        span[i] = counter;
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