// Program to find maximum and minimum of an array using minimum number of comparisons

/* Compare in pairs ->
    If n is odd:  3*(n-1)/2  
    If n is even: 1 Initial comparison for initializing min and max, 
                  3(n-2)/2 comparisons for rest of the elements  = 1 + 3*(n-2)/2 = 3n/2 - 2
*/

// Time Complexity: O(n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int min;
    int max;
};

Pair getMinMax(vector<int> arr, int n){
    struct Pair minmax;
    int i;
    if(n % 2 == 0){
        if(arr[0] > arr[1]){
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else {
            minmax.max = arr[1];
            minmax.min = arr[0];
        }      
        i = 2;
    }
    else {
        minmax.max = minmax.min = arr[0];
        i = 1;
    }

    while(i < n-1){
        if(arr[i] > arr[i+1]){
            if(arr[i] > minmax.max)
                minmax.max = arr[i];
            if(arr[i+1] < minmax.min)
                minmax.min = arr[i+1];
        }
        else {
            if(arr[i+1] > minmax.max)
                minmax.max = arr[i+1];
            if(arr[i] < minmax.min)
                minmax.min = arr[i];

        }
        i+=2;
    }
    return minmax;

}

int main(){
    vector<int> arr = {1000, 11, 445, 1, 330, 3000};
    Pair minmax = getMinMax(arr, arr.size());
    cout << "Max: " << minmax.max << endl << "Min: " << minmax.min << endl;
    return 0;
}