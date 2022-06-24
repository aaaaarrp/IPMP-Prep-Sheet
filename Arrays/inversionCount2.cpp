// Program to Count Inversions in an array

// Enhance Merge Sort
// Time: O(nlogn) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right){
    int i, j, k, count = 0;
    i = left;
    j = mid;
    k = right;

    while(i <= mid-1 && j <= right){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            count += (mid-1);
        }
    }

    while(i <= mid-1)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];

    return count;
}

int mergeSort(int arr[], int temp[], int left, int right){
    int mid, count = 0;
    if(left < right){
        mid = (left+right)/2;
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid+1, right);
        count += merge(arr, temp, left, mid+1, right);
    }
    return count;
}

int countInversion(int arr[], int n){
    int temp[n];
    return mergeSort(arr, temp, 0, n-1);
}

int main(){
    int arr[] = {1,20,6,4,5};
    cout << countInversion(arr, 5) << endl;
    return 0;

}