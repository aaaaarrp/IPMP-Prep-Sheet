// Program to Find the first circular tour that visits all petrol pumps

// Without making an actual circular tour
// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

struct PetrolPump{
    int petrol;
    int distance;
};

int printTour(PetrolPump arr[], int n){
    int start;
    for(int i=0; i<n; i++){
        if(arr[i].petrol >= arr[i].distance)
            start = i;
            break;
    }

    int curr_petrol = 0;
    int i = start;
    while(i < n){
        curr_petrol += arr[i].petrol-arr[i].distance;
        if(curr_petrol < 0){
            i++;
            for(; i<n; i++){
                if(arr[i].petrol >= arr[i].distance)
                    start = i;
                    curr_petrol = 0;
                    break;
            }
        }  
        else
            i++;
    }

    if(curr_petrol < 0)
        return -1;
    
    for(int j=0; j<start; j++){
        curr_petrol += arr[i].petrol-arr[i].distance;
        if(curr_petrol < 0)
            return -1;
    }

    return start;
}

int main(){
    PetrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr)/sizeof(arr[0]);

    int start = printTour(arr, n);
    (start == -1) ? cout << "No Solution" << endl : cout << "Starting index: " << start << endl;
    return 0;
}