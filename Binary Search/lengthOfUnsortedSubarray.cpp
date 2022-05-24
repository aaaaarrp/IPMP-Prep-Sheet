// Using Binary search to find the Minimum length Unsorted Subarray,
// sorting which makes the complete array sorted - Time: O(n)

#include <bits/stdc++.h>
using namespace std;

void printUnsorted(vector<int> nums, int size){
    int start = 0, end = size-1, i, max, min;

    // Find the candidate unsorted subarray 
    for(start=0; start < size-1; start++){     //start
        if(nums[start] > nums[start+1])
            break;
    }

    if(start == size-1)
        cout << "The complete array is sorted.";
    
    for(end=size-1; end > 0; end--){        // end
        if(nums[end] < nums[end-1])
            break;
    }

    // Check whether sorting the candidate unsorted subarray makes the complete array sorted or not.

    max = nums[start], min = nums[start];

    for(i=start; i <= end; i++){        // finding min & max
        if(nums[i] > max)
            max = nums[i];
        if(nums[i] < min)
            min = nums[i];
    }

    // If not, then include more elements in the subarray. 
    for(i=0; i < start; i++){
        if(nums[i] > min){
            start = i;
            break;
        }
    }

    for(i=size-1; i > end; i--){
        if(nums[i] < max){
            end = i;
            break;
        }
    }

    cout << "The unsorted subarray which"
         << " makes the given array sorted lies between the indices "
         << start << " and " << end << endl;

    
}

int main()
{
    vector<int> nums = {0, 1, 15, 25, 6, 7, 30, 40, 50};
    int size = nums.size();
    printUnsorted(nums, size);
    return 0;
}
