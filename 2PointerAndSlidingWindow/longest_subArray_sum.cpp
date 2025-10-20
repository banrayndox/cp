#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> array = {1,2,3,2,3,3,7,3,7,3,1,1,1};
    int maxLen = 0;
    int start = 0;
    int end = 0;
    int sum = 15;
    int currentWindow = 0 ;
    while(end < array.size()){
        currentWindow += array[end];
        if(currentWindow <= sum ){
            int len = (end - start + 1);
            maxLen = max(maxLen, len);
        }
        while(currentWindow>sum && start <= end){
            currentWindow-=array[start++];
        }
        end++;
    }
    cout << maxLen << endl;
    
}
