#include <iostream>
using namespace std;
int print(int* array, int n){
    int max = array[0];
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            int current = 0;
            for(int k=start; k<=end; k++){
            current+= array[k];
            }
            if(current>max) max = current;
        }
    }
    return max;
}

int main(){
    int array[3] = {1,2,3};
    int result = print(array,3);
    cout << result << endl;
    return 0;
}
