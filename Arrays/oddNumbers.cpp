
// Program to find the element occurring odd number of times

// Brute force method - Time complexity: O(n*n)

#include<bits/stdc++.h>
using namespace std;

int getOddOccurrence(int a[], int n){       

    for(int i = 0; i < n; i++){

        int count = 0;

        for(int j = 0; j < n; j++){

            if(a[i] == a[j])
                count++;
        }

        if((count % 2) != 0)
            return count;
    }
    return -1;
}

int main()
    {
        int arr[] = { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 };
        int n = sizeof(arr) / sizeof(arr[0]);
 
        cout << getOddOccurrence(arr, n) << endl;
 
        return 0;
    }