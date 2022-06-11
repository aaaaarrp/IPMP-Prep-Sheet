// Program to print all subsets of a set
// Power set P(S) of a set S is the set of all subsets of S.

// Time Complexity: O(n(2^n)) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void printPowerSet(char *set, int n){
    unsigned int pow_set_size = pow(2, n);
    int counter, j;

    for(counter = 0; counter < pow_set_size; counter++){
        cout << "{";
        for(j=0; j<n; j++){
            if(counter & (1 << j))
                cout << set[j];
        }
        cout << "} ";
    }

}

int main(){
    char set[] = {'a', 'b', 'c'};
    printPowerSet(set, 3);
    return 0;
}