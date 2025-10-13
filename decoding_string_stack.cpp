// string decoding

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decode(string &input){
stack <string> text;
stack <int> number;
string current = "";
int num = 0;
for ( char ch: input ) {
    if(isdigit(ch)){
        num = ( num * 10 ) + ( ch - '0' );
    }
    else if ( ch == '[' ) {
        number.push(num);
        text.push(current);
        num = 0;
        current = "";
    } else if ( ch == ']' ) {
        int count = number.top(); number.pop();
        string temp = "";
        for(int i = 0; i < count; i++){
            temp += current;
        }
        current = text.top() + temp; text.pop();
        
    } else {
        current += ch;
    }
}    
    return current;
}

int main(){
    
    string input = "3[a2[c]]";
    cout << decode(input) << endl;
    
    
    
    return 0;
}
