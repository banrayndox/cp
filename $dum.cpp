#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> array = {1,4,-2,-3,-2,-1,9,7,2};
    sort(array.begin(),array.end());
    int len = array.size();
    vector<vector<int>>result;
    for(int i=0; i<len-3; i++){
        if(i>0 && array[i]==array[i-1]) continue;
        for(int j=i+1; j<len-2; j++){
            if(j>i+1 && array[j]==array[j-1]) continue;
            int start = j+1;
            int end = len-1;
            while(start<end){
                int sum = array[i]+array[j]+array[start]+array[end];
                if(sum==0) {
                    result.push_back({array[i],array[j],array[start],array[end]});
                    while(start<end && array[start]==array[start+1]){
                        start++;
                    }
                    while(start<end && array[end]==array[end-1]) {
                        end--;
                    }
                    start++;
                    end--;
                }else if(sum>0){
                    end--;
                }else{
                    start++;
                }
            }
        }
    }
    
    int newLen = result.size();
    for(int i=0; i<newLen; i++){
        cout << "[";
        
        for(int j=0; j<4; j++){
            cout << result[i][j] ;
            if( j!=3) cout <<",";
         }
        
        cout << "]";
        if( i!=newLen-1) cout <<",";
    }
    cout << endl;
    
    return 0;
}
