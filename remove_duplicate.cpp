#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> array = {1,1,2,2,3,3,4,4};
    int len = array.size();
    int i=0;
    for(int j=1; j<len; j++){
        if(array[j]!=array[i]){
         i++;
        array[i] = array[j];
      
        }
    }
    for(int j=0; j<=i; j++){
        cout << array[j] << " ";
    }
    
    
    
    
    return 0;
}
