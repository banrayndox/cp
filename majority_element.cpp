#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> array = {1,2,1,2,1,3,3,3,3,2,3,3,3};
    int count = 0;
    int cand = 0;
    for(int x: array){
        if(count == 0) cand = x;
        if(cand==x) count ++;
        else count--;
    }
    cout << cand << endl;
    
    return 0;
}
