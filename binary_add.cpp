#include <iostream>
using namespace std;
#include <string>

int main(){
    string a,b;
    cin >> a >> b;
    
    string result = "";
    int carry = 0;
    int lenA = a.size()-1;
    int lenB = b.size()-1;
    while( lenA>=0 || lenB >=0 || carry ){
        int sum = carry;
        if(lenA>=0) {
            sum+= a[lenA--] - '0';
        }
        if(lenB>=0){
            sum+= b[lenB--] - '0';
        }
        result =  char (sum%2 + '0' ) + result;
        carry = sum/2;
    }
    
    cout << result << endl;
    return 0;
}
