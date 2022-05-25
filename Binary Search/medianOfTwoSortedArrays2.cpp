// program to find the median of the array obtained after merging 2 arrays of same size - Time: O(logn) - Space: O(1)
// By comparing the medians of two arrays (DAC)

#include<bits/stdc++.h>
using namespace std;

int median(int nums[], int n){
    if(n%2 == 0)
        return (nums[n/2]+nums[n/2-1])/2;
    return nums[n/2];
}

int getMedian(int nums1[], int nums2[], int n){
    if(n <= 0)
        return -1;
    if(n == 1)
        return (nums1[0]+nums2[0])/2;
    if(n == 2)
        return (max(nums1[0], nums2[0]) + min(nums1[1], nums2[1])) / 2;

    int m1 = median(nums1, n);
    int m2 = median(nums2, n);

    if(m1 == m2)
        return m1;
    
    if(m1 < m2){
        if(n%2 == 0)
            return getMedian(nums1+n/2-1, nums2, n-n/2+1);
        return getMedian((nums1+n/2), nums2, n-n/2);
    }

    if(n%2 == 0)
        return getMedian(nums1, nums2+n/2-1, n-n/2+1);
    return getMedian(nums1, nums2+n/2, n-n/2);
}

int main(void){
    int nums1[] = {1, 12, 15, 26, 38};
    int nums2[] = {2, 13, 17, 30, 45};

    int n1 = sizeof(nums1)/sizeof(nums1[0]);
    int n2 = sizeof(nums2)/sizeof(nums2[0]);

    if(n1 == n2)
        cout << "Median is " << getMedian(nums1, nums2, n1) << endl;
    else
        cout << "Not applicable for arrays of unequal sizes." << endl;
    
    return 0;
}