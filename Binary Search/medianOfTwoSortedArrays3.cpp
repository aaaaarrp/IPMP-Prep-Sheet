// program to find the median of the array obtained after merging 2 arrays of same size - Time: O(nlogn) - Space: O(1)
// By taking union w/o extra space

#include<bits/stdc++.h>
using namespace std;

int getMedian(vector<int> nums1, vector<int> nums2, int n){
    int i = n-1;
    int j = 0;
    while(nums1[i] > nums2[j] && i > -1 && j < n)
        swap(nums1[i--], nums2[j++]);
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    return (nums1[n-1]+nums2[0])/2;
}

int main(){
    vector<int> nums1 = {1, 12, 15, 26, 38};
    vector<int> nums2 = {2, 13, 17, 30, 45};

    if(nums1.size() == nums2.size())
        cout << "Median is " << getMedian(nums1, nums2, nums1.size()) << endl;
    else
        cout << "Not applicable for arrays of unequal sizes." << endl;
    
    return 0;

}