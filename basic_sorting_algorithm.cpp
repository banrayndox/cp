#include <iostream>
#include <string.h>
#include <climits>
#include <algorithm>
using namespace std;


int bubble(int *array, int length){
    for(int i=0; i<length-1; i++){
        for(int j=0; j<length-i-1; j++){
            if(array[j]<array[j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    return 0;
}


int selection(int *array, int length){
    
    for(int i=0; i<length; i++){
        int index = i;
        for(int j=i+1; j<length; j++){
            if(array[index] < array[j]){
                int temp = array[index];
                array[index] = array[j];
                array[j] = temp;
            }
        }
    }
    return 0;
}



int insertion(int* array, int length){
    
    for(int i=1; i<length; i++){
        int key = array[i];
        int prev = i-1;
        while(array[prev]<key && prev>=0){
            swap(array[prev], array[prev+1]);
            prev--;
        }
        array[prev+1] = key;
    }
    
    return 0;
    
}






int count(int *array, int length){
    int maxValue = INT_MIN;
    int minValue = INT_MAX;
    for(int i=0; i<length; i++){
        if(array[i]>maxValue) maxValue  = array[i];
        if(array[i]<minValue) minValue = array[i];
        
    }
    int freq[10000];
    memset(freq,0,sizeof(freq));
    
    for(int i=0; i<length; i++){
        freq[array[i]]++;
    }
    int index = 0;
    for(int i=maxValue; i>=minValue; i--){
        while(freq[i]>0){
            array[index++] = i;
            freq[i]--;
        }
    }
    
    
    return 0;
}




int main(){
    int array[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int length  = sizeof(array) / sizeof(array[0]);
    insertion(array, length);
    for(int i=0; i<length; i++){
        cout << array[i] <<endl;
    }
    
    
    return 0;
}
