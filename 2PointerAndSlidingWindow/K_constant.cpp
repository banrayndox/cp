#include <iostream>
using namespace std;
int main(){
    int array[] = {-1,1,2,3,4,5,6,7,8};
    int len = sizeof(array) / sizeof(array[0]);
    int k = 4;
    int window_sum = 0;
    for(int i=0; i<4; i++){
        window_sum+=array[i];
    }
    int index = 0;
    int max = window_sum;
    for(int i=4; i<len; i++){
        window_sum = window_sum - array[index++] + array[i];
        if(window_sum>max) max = window_sum;
    }
    cout << max << endl;
    return 0;
}
