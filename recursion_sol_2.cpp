#include <iostream>
#include <vector>
using namespace std;
void occur(vector<int> array, int n, int index,int key){
if(index==n){
    return;
}
if(array[index]==key) cout << index << " ";
index++;
occur(array,n,index,key);
    
}
int main(){
vector<int> array = {3,2,4,5,6,2,7,2,2};    
occur(array,9,0,2);
    return 0;
}
