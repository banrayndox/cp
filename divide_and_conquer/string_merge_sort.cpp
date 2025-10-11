#include <iostream>
#include <vector>
#include <string>
using namespace std;
void mergeSort(vector<string> &arr, int st, int mid, int end){
    int i = st;
    int j = mid+1;
    vector<string> temp;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]) {
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int i=st,x=0; i<=end; i++){
        arr[i] = temp[x++];
    }
}

void merge(vector<string> &arr, int st, int end){
     if (st >= end) return; 
    int mid  = ( end - st ) / 2 + st;
    merge(arr, st, mid);
    merge(arr, mid+1, end);
    mergeSort(arr, st, mid, end);
}

int main(){
    
    vector<string> arr = { "sun", "earth", "mars", "mercury" };
    int start = 0;
    int end = arr.size()-1;
  merge(arr,start,end);
    for(string a : arr){
        cout << a << endl;
    }
    
    return 0;
}
