#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> array;
    int n;
    cin >> n;
    int target;
    cin >> target;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        array.push_back(x);
    }
    sort(array.begin(),array.end());
    int start = 0;
    int end = n-1;
    while(start<end){
        int sum = array[start]+array[end];
        if(sum==target){
            cout << array[start] << " , " << array[end] << endl;
            start++;
            end--;
        }
       else if(sum<target) start++;
       else if(sum>target) end--;
    }
    
    
    return 0;
}
