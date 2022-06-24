// PRogram to Segregate 0s and 1s in an array

// By counting 0s & 1s
// Time complexity: O(2n) ≅ O(n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void segregate0s1s(vector<int> &arr, int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0)
            count ++;
    }

    for(int i=0; i<count; i++)
        arr[i] = 0;

    for(int i=count; i<n;i++)
        arr[i] = 1;

}

int main()
{
    vector<int> arr = {1, 0, 1, 0, 1, 1, 0, 0, 0};
    int i = 0;
 
    segregate0s1s(arr, arr.size());
 
    cout <<"Array after segregation ";
    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
 
    return 0;
}