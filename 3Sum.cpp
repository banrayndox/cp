#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> array = {-1,0,1,2,-1,-4};
    int len = array.size();
    sort(array.begin(),array.end());
    vector<vector<int>> result;
    for(int i=0; i<len-2; i++){
        if(i>0 && array[i]==array[i-1]) continue;
        int start = i+1, end = len-1;
        while(start<end){
            int sum = array[i] + array[start] + array[end];
            if(sum == 0) {
                result.push_back({array[i],array[start],array[end]});
                while(start<end && array[start]==array[start+1]) start++;
                while(start<end && array[end]==array[end-1]) end--;
            start++;
            end--;
            }
            else if(sum > 0) end--;
            else if(sum < 0) start++;

    }
    }
    for(int i=0; i<result.size(); i++){
        cout << "[";
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j];
            if(j<result[i].size()-1) cout << ",";
        }
        cout << "]";
        if(i<result.size()-1) cout << ",";
    }
    
    
    return 0;
}
