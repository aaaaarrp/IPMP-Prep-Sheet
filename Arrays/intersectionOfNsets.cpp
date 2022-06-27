// Program to find the intersection of n sets

// Time Complexity: O(n) - Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

vector<int> getIntersection(vector<vector<int>> &sets){
    vector<int> res;
    int small_index = 0;
    int minSize = sets[0].size();

    for(int i=0; i<sets.size(); i++){
        sort(sets[i].begin(), sets[i].end());
        if(minSize > sets[i].size()){
            minSize = sets[i].size();
            small_index = i;
        }
    }

    map<int, int> mapSmall;
    for(int i=0; i<sets[small_index].size(); i++){
        if(mapSmall.find(sets[small_index][i]) == mapSmall.end())
            mapSmall[sets[small_index][i]] = 1;
        else
            mapSmall[sets[small_index][i]]++;
    }

    map<int, int>:: iterator it;
    for(it = mapSmall.begin(); it != mapSmall.end(); it++){
        int element = it->first;
        int freq = it->second;
        bool bFound = true;

        for(int j=0; j<sets.size(); j++){
            if(j != small_index){
                if(binary_search(sets[j].begin(), sets[j].end(), element)){
                    int left_index = lower_bound(sets[j].begin(), sets[j].end(), element) - sets[j].begin();
                    int right_index = upper_bound(sets[j].begin(), sets[j].end(), element) - sets[j].begin();
                    if(right_index - left_index < freq)
                        freq = right_index-left_index;
                }
                else {
                    bFound = false;
                    break;
                }
            }
        }

        if(bFound){
            for(int i=0; i<freq; i++)
                res.push_back(element);
        }
    }

    return res;
}

int main(){
    vector<vector<int>> sets;
    vector<int> set1;
    set1.push_back(1);
    set1.push_back(1);
    set1.push_back(2);
    set1.push_back(2);
    set1.push_back(5);

    sets.push_back(set1);

    vector<int> set2;
    set2.push_back(1);
    set2.push_back(1);
    set2.push_back(4);
    set2.push_back(3);
    set2.push_back(5);
    set2.push_back(9);

    sets.push_back(set2);

    vector<int> set3;
    set3.push_back(1);
    set3.push_back(1);
    set3.push_back(2);
    set3.push_back(3);
    set3.push_back(5);
    set3.push_back(6);

    sets.push_back(set3);

    vector<int> res = getIntersection(sets);

    for(auto it: res)
        cout << it << " ";
    cout << endl;

    return 0;
}