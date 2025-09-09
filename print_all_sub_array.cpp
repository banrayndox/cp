#include <iostream>
#include <vector>
using namespace std;
void print(int* array, int n){
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            for(int k=start; k<=end; k++){
                cout << array[k] << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    int array[3] = {1,2,3};
    print(array,3);
    
    return 0;
}
