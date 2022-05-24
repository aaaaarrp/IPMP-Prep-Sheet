
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {0, -1, 2, -3, 1};
    int x = -2;
    int size = sizeof(arr)/sizeof(arr[0]);
    if(checkpair(arr, x, size))
        cout << "Yes";
    else
        cout << " No";
}