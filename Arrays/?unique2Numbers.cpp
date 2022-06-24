// Program to find the two non-repeating elements in an array of repeating elements/ Unique Numbers 2 

// Using Sorting. In the sorted array, by comparing adjacent elements we can easily get the non-repeating elements.
// Time:  O(nLogn)

#include<bits/stdc++.h>
using namespace std;

void get2NonRepeatingNos(int arr[], int size){
    sort(arr, arr+size);
    int i;

    for(i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //for(i=0; i<size; i = i+2){
        if(arr[0] == arr[1]){
            cout << i << " ";
        }
    //}
}

int main()
{
    int arr[] = { 2, 3, 7, 9, 11, 2, 3, 11 };
    int n = sizeof(arr) / sizeof(*arr);
    get2NonRepeatingNos(arr, n);
    return 0;
}