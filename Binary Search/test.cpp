#include <iostream>
using namespace std;

int maxInBitonic(int arr[], int l, int r)
{

	while (l <= r) {

		int m = l + (r - l) / 2; // m = (l + r) / 2

		/****Base Cases Starts*****/

		/* If there are two elements and first is greater
		then the first element is maximum */
		if ((r == l + 1) && arr[l] >= arr[r])
			return arr[l];

		/* If there are two elements and second is greater
		then the second element is maximum */

		if ((r == l + 1) && arr[l] < arr[r])
			return arr[r];

		/* If we reach a point where arr[mid] is greater
		than both of its adjacent elements arr[mid-1] and
		arr[mid+1], then arr[mid] is the maximum
		element*/
		if (arr[m] > arr[m + 1] && arr[m] > arr[m - 1])
			return arr[m];

		/****Base Case ends *****/

		// move to left with l and r=m-1
		if (arr[m] > arr[m + 1] && arr[m] < arr[m - 1])
			r = m - 1;

		else
			l = m + 1; // move to right with l=m+1 and r
	}
	// if we reach here, then element was
	// not present
	return -1;
}

// Driver function
int main()
{
	int arr[] = {0, 1, 1, 2, 2, 2, 2, 2, 3, 4, 4, 5, 3, 3, 2, 2, 1, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The maximum element is "
		<< maxInBitonic(arr, 0, n - 1);
	return 0;
}
