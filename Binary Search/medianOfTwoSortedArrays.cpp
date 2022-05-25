// program to find the median of the array obtained after merging 2 arrays of same size - Time: O(n) - Space: O(1)
// count while Merging

#include<bits/stdc++.h>
using namespace std;

int getMedian(vector<int> nums1, vector<int> nums2, int size){
    int i = 0;
    int j = 0;
    int m1 = -1, m2 = -1;

    for(int count=0; count<=size; count++){
        if(i == size){
            m1 = m2;
            m2 = nums2[0];
            break;
        }
        else if(j == size){
            m1 = m2;
            m2 = nums1[0];
            break;
        }

        if(nums1[i] <= nums2[j]){
            m1 = m2;
            m2 = nums2[i];
            i++;
        }
        else{
            m1 = m2;
            m2 = nums1[j];
            j++;
        }
    }

    return (m1+m2)/2;

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