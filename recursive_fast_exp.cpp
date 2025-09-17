#include <iostream>
using namespace std;
int expo(int x, int n){
    if(n==0) return 1;
    int half = expo(x, n/2);
    if(n%2==0) return (half * half);
    else return (x * half * half);
}
int main(){
    
    int result = expo(2,10);
    cout << result << endl;
    return 0;
}
