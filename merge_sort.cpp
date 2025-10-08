#include <iostream>
#include <vector>
using namespace std;

void mergesort(int array[], int st, int mid, int end){
    
    vector<int>temp;
    int i = st;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(array[i]<array[j]){
            temp.push_back(array[i++]);
        }else{
            temp.push_back(array[j++]);
        }
        
    }
    
    while(i<=mid){
        temp.push_back(array[i++]);
    }
    while(j<=end){
        temp.push_back(array[j++]);
    }
    for(int i=st,x=0; i<=end; i++){
        array[i] = temp[x++];
    }
    
    
}

void merge(int array[], int st, int end){
if(st>=end) return;
int mid = st + (end - st ) / 2 ;
    merge(array, st, mid);
    merge(array, mid+1, end);
    
    mergesort(array, st, mid, end);
    
}
int main(){
    int array[6] = {11,12,32,24,15,6};
    int n = 6;
    merge(array,0,n-1);
    for(int x: array){
        cout << x << endl;
    }
    
    
    return 0;
}
