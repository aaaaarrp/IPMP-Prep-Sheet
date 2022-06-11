// Program to implement LRU cache

// TIME: SEARCHING O(1) & SHIFTING O(1)

#include<bits/stdc++.h>
using namespace std;

class LRUCache {

    list<int> dq;
    unordered_map<int, list<int>::iterator> map;
    int csize;
    int pagefault = 0;

public:

    LRUCache(int x){
        csize = x;
    }

    void refer(int x){
        if(map.find(x) == map.end()){       // not present
            if(dq.size() == csize){
                int last = dq.back();
                dq.pop_back();
                map.erase(last);
            }
            pagefault++;
        }
        else        // present
            dq.erase(map[x]);
        
        dq.push_front(x);   // update reference
        //pagefault++;
        map[x] = dq.begin();
    }

    void display(){
        for(auto i=dq.begin(); i != dq.end(); i++)
            cout << (*i) << " ";
        //cout << "\n" << pagefault << endl;
    }
};

int main()
{
    LRUCache ca(4);
  
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
  
    return 0;
}