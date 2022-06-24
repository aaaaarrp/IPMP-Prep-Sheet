// Program to Shuffle a given array using Fisher–Yates shuffle Algorithm

// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void randomize (vector<int> &arr, int n){

	srand(time(NULL));  // everytime unique random element

    for(int i=n-1; i >0; i--){
        int j = rand()%(i+1);
        swap(arr[i], arr[j]);
    }
    
    for(auto it: arr)
        cout << it << " ";
    cout << endl;
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
	randomize (arr, arr.size());
	return 0;
}
