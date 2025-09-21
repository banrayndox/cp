#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> call(vector<int> &array,int len){
    vector<int>result(len);
    stack<int>span;
    for(int i=0; i<len; i++){
        
        while(!span.empty() && array[span.top()]<=array[i]){
            span.pop();
        }
        if(span.empty()){
            result[i] = i+1;
        }else{
            result[i] = i-span.top();
        }
        span.push(i);
    }
    return result;
}
int main(){
    vector<int>array = {100,80,60,60,60,90,100};
    int len = array.size();
    vector<int>span = call(array,len);
    for(int x: span){
        cout << x << " ";
    }
    
}
