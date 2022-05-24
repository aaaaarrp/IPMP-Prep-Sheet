
// C++ code to demonstrate Divide and Conquer Algorithm Finding maximum & minimum number

#include<bits/stdc++.h>
using namespace std;

int DAC_Max(vector<int> &array, int index, int size){
    int maximum;
    if(index >= size-2){
        if(array[index] > array[index+1])
            return array[index];
        else 
            return array[index+1];
    }
    maximum = DAC_Max(array, index+1, size);
    if(array[index] > maximum) 
        return array[index];
    else
        return maximum;
}

int DAC_Min(vector<int> &array, int index, int size){
    int minimum;
    if(index >= size-2){
        if(array[index] < array[index+1])
            return array[index];
        else
            return array[index+1];
    }
    minimum = DAC_Min(array, index+1, size);
    if(array[index] < minimum)
        return array[index];
    else
        return minimum;
}

int main(){
    vector<int> array = {120, 34, 54, 32, 58, 11, 90};
    int maximum, minimum;
    maximum = DAC_Max(array, 0, array.size());
    minimum = DAC_Min(array, 0, array.size());
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;

}