// Stable Marriage Problem

// Using Gale–Shapley algorithm
// Time complexity: O(n^2) 

/* 
    Initialize all men and women to free
    while there exist a free man (m) who still has a woman (w) to propose to 
    {
        w = m's highest ranked such woman to whom he has not yet proposed
        if w is free
            (m, w) become engaged
        else 
            some pair (m', w) already exists
        if w prefers m to m'
            (m, w) become engaged
            m' becomes free
        else
            (m', w) remain engaged    
    }
*/
#include<bits/stdc++.h>
using namespace std;

#define N 4

bool wPrefersM1overM(int prefer[2*N][N], int w, int m, int m1){
    for(int i=0; i<N; i++){
        if(prefer[w][i] == m1)
            return true;
        if(prefer[w][i] == m)
            return false;
    }
}

void stableMarriage(int prefer[2*N][N]){
    int wPartner[N];
    bool mFree[N];

    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    while(freeCount > 0){
        int m;
        for(m=0; m<N; m++){
            if(mFree[m] == false)
                break;
        }
        for(int i=0; i<N && mFree[m] == false; i++){
            int w = prefer[m][i];
            if(wPartner[w-N] == -1){
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }
            else {
                int m1 = wPartner[w-N];
                if(wPrefersM1overM(prefer, w, m, m1) == false){
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }

    cout << "Women  Men" << endl;
    for(int i=0; i<N; i++)
        cout << " " << i+N << "\t" << wPartner[i] << endl;
}

int main()
{
    int prefer[2*N][N] = {  {7, 5, 6, 4},
                            {5, 4, 6, 7},
                            {4, 5, 6, 7},
                            {4, 5, 6, 7},       // men 0 to N-1
                            {0, 1, 2, 3},
                            {0, 1, 2, 3},
                            {0, 1, 2, 3},
                            {0, 1, 2, 3},       // women N to 2*N – 1
                        };
    stableMarriage(prefer);
  
    return 0;
}