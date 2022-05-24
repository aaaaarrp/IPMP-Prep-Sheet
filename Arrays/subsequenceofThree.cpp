
// Find a sorted subsequence of size 3 in linear time - Using auxilary space : O(n)

#include <bits/stdc++.h>
using namespace std;

void find3Numbers(int arr[], int size){
    int max = size-1;
    int min = 0;
    int i;

    int* smaller = new int[size];
    smaller[0] = -1;
    for(int i=1; i<size; i++){
        if(arr[i] <= arr[min]){
            min = i;
            smaller[i] = -1;
        }
        else
            smaller[i] = min;
    }

    int* greater = new int[size];
    greater[size-1] = -1;
    for(int i=size-2; i>=0; i--){
        if(arr[i] >= arr[max]){
            max = i;
            greater[i] = -1;
        }
        else
            greater[i] = max;
    }

    for(int i=0; i<size; i++){
        if(smaller[i] != -1 && greater[i] != -1){
            cout << arr[smaller[i]] << ", " << arr[i] << ", " << arr[greater[i]] << endl;
            return;
        }
    }

    cout << "No Such numbers";

    delete[] smaller;
    delete[] greater;

    return;
}

int main()
{
    int arr[] = { 12, 11, 10, 5, 6, 2, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    find3Numbers(arr, n);
    return 0;
}