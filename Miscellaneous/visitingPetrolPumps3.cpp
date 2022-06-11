// Program to Find the first circular tour that visits all petrol pumps

#include<bits/stdc++.h>
using namespace std;

struct PetrolPump{
    int petrol;
    int distance;
};

int printTour(PetrolPump arr[], int n){
    int start = 0;
    int capacity = 0; 
    int deficit = 0;

    for(int i=0; i<n; i++){
        capacity += arr[i].petrol-arr[i].distance;
        if(capacity < 0){
            start = i+1;
            deficit += capacity;
            capacity = 0;
        }
    }

    return (deficit+capacity >= 0) ? start : -1;
}

int main(){
    PetrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr)/sizeof(arr[0]);

    int start = printTour(arr, n);
    (start == -1) ? cout << "No Solution" << endl : cout << "Starting index: " << start << endl;
    return 0;
}