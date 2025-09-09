#include <iostream>
using namespace std;
int max(int* array, int n){
    int highest = array[0];
    int current = 0;
    for(int start=0; start<n; start++){
        current+= array[start];
        if(current > highest) highest = current;
        if(current < 0) current = 0;
    }
    return highest;
    
}
int main(){
    
    int array[3] = {1,2,3};
    int result = max(array,3);
    cout << result << endl;
    
    return 0;
}
