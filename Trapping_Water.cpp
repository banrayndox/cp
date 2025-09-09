#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int trapped(vector<int>array){
    int n = array.size();
    int water = 0;
    vector<int>leftMax(n);
    vector<int>rightMax(n);
    leftMax[0] = array[0];
    for(int i=1; i<n; i++){
        leftMax[i] = max(leftMax[i-1], array[i]);
    }
    rightMax[n-1] = array[n-1];
    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1],array[i]);
    }
    
    for(int i=0; i<n; i++){
        water+= min(leftMax[i],rightMax[i])-array[i];
    }
    return water;
    
}

int main(){
    vector<int>array = {0,1,0,2,1,0,1,3,2,1,2,1};
    int water = trapped(array);
    cout << water << endl;
    
    return 0;
}
