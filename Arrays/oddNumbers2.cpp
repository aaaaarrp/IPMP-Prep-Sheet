
// Program to find the element occurring odd number of times

// Hashing - Time Complexity: O(n) + Extra space

#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int getOddOccurrence(int a[], int n){      

    unordered_map<int, int> hash;

    for(int i=0; i < n; i++){
        hash[a[i]]++;
    }

    for(auto i : hash){
        if(i.second%2 != 0)
            return i.first;
    }
    return -1;
}

int main()
    {
        int arr[] = { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 };
        int n = sizeof(arr) / sizeof(arr[0]);
 
        cout << getOddOccurrence(arr, n);
 
        return 0;
    }