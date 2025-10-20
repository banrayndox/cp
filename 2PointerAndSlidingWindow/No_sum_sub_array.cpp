#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> array = {1,2,3,2,3,3,7,3,7,3,1,1,1};
    int maxLen = 0;
    int start = 0;
    int end = 0;
    int sum = 5;
    int currentWindow = 0 ;
    int count = 0;
    while(end < array.size()){
        currentWindow += array[end];
        while(currentWindow>sum && start <= end){
            currentWindow-=array[start++];
        }
        if(currentWindow == sum ){
        count++;
        }
        end++;
    }
    cout << count << endl;
    
}
