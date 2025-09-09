#include <iostream>
using namespace std;
int max(int* array, int n){
    int maximum = array[0];
    for(int start = 0; start<n; start++){
        int current = 0;
        for(int end = start; end<n; end++){
            current+= array[end];
            if(current > maximum) maximum = current;
        }
    }
    return maximum;
}


int main(){
    int array[3] = {1,2,3};
    int result  = max(array,3);
    cout << result << endl;
    return 0;
}
