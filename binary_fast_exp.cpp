#include <iostream>
using namespace std;
int main(){
    int base = 3;
    int ex = 5;
    int res = 1;
    while(ex>0){
        int last = ex & 1;
        if(last % 2 == 1 ){
            res*=base;
            
        }
        base*=base;
        ex >>= 1;
    }
    cout << res;
    
    
    
    return 0;
}
