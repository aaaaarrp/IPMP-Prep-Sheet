// Using Binary Search to find the number of occurances of any element in a sorted array - Time: O(log) (improved)

#include<bits/stdc++.h>
using namespace std;

int counting(vector<int> nums, int key, int size){
    auto low = lower_bound(nums.begin(), nums.end(), key);

    if(low == nums.end() || *low != key)
        return 0;

    auto high = upper_bound(low, nums.end(), key);

    return high-low;


}

int main()
{
  vector<int> nums = {1, 2, 2, 3, 3, 3, 3};
  int x =  2;  
  int n = nums.size();
  int c = counting(nums, x, n);
  cout << x << " occurs " << c << " times." << endl;
  return 0;
}