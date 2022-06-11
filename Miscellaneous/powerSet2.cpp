// Program to print all subsets of a set
// Power set P(S) of a set S is the set of all subsets of S.

// Sorted by cardinality
// Time Complexity: O(n(2^n)) - Auxiliary Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void printPowerSet(char *arr, int n){
    bool *contain = new bool[n]{0};
    cout << "{}" << " ";

    for(int i=0; i<n; i++){
        contain[i] = 1;
        do
        {
            cout << "{";
            for(int j=0; j<n; j++){
                if(contain[j])
                    cout << arr[j];
            }
            cout << "} ";
        } while(prev_permutation(contain, contain+n));
    }
}

int main(){
    char set[] = {'a', 'b', 'c'};
    printPowerSet(set, 3);
    return 0;
}