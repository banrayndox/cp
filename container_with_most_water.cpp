#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int>array={1,8,6,2,5,4,8,3,7};
    int len = array.size();
    int start = 0;
    int end = len-1;
    int max = 0;
    while(start<end){
        int gap = end-start;
        int current = min(array[start],array[end]) * gap; 
        if(current>max) max = current;
        if(array[start]>array[end]) end--;
        else start++;
    }
    cout << max << endl;
    return 0;
}
