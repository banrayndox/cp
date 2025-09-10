#include <iostream>
using namespace std;
int hcf(int a, int b){

    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b){
    return (a*b) / hcf(a,b);
}
int main(){
    int a,b;
    cin >> a >> b;
    int l = lcm(a,b);
     int h = hcf(a,b);
    cout << "HCF of " << a << " and " << b << "is:" << h << endl;
     
    cout << "LCM of " << a << " and " << b << "is:" << l << endl;
    
    return 0;
}
