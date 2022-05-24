// Using Binary Search to Merge an array of size n into another array of size m+n

#include<bits/stdc++.h>
using namespace std;

#define NA -1

void printArray(int arr[], int size){
    for(int i=0; i < size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

void moveToEnd(int mPlusN[], int size)
{
    int j = size - 1;
    for (int i = size - 1; i >= 0; i--){
      if (mPlusN[i] != NA)
      {
         mPlusN[j] = mPlusN[i];
         j--;
      }
    }

}

void merge(int mPlusN[], int N[], int m, int n){

    int i = n;  // Current index of i/p part of mPlusN
    int j = 0;  // Current index of N
    int k = 0;  // Current index of output mPlusN

    while(k < (m + n)){
        if((j == n) || (i < (m + n) && mPlusN[i] <= N[j])){
            mPlusN[k] = mPlusN[i];
            k++;
            i++;
        }
        else{
            mPlusN[k] = N[j];
            k++;
            j++;
        }
    }

}

int main(){

   int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
   int N[] = {5, 7, 9, 25};

   int n = sizeof(N)/sizeof(N[0]);
   int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;


   moveToEnd(mPlusN, m+n);
 
   merge(mPlusN, N, m, n);

   printArray(mPlusN, m + n);
 
   return 0;
}