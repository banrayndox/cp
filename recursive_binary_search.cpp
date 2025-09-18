#include <iostream>
#include <vector>
using namespace std;
void re(int array[],int si,int ei, int key){
    
    if(si > ei) return;
    int mid = si + (ei-si) / 2;
    if(key==array[mid]) {
        cout << mid << endl;
        return;
    }
    if(key>array[mid]){
        re(array,mid+1,ei,key);
    } else{
        re(array,si,mid-1,key);
    }
    
}
int main(){
    int array[7] = {1,2,3,4,5,6,7};
    re(array,0,6,5);
}
