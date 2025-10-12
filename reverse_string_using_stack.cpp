#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverse(string name){
stack<char> temp;
string temp2;
for(char ch: name){
    temp.push(ch);
}
while(!temp.empty()){
    temp2+=temp.top();
    temp.pop();
}
return temp2;
}

int main(){
    
string name = "Rakib";    
cout << "Before reverse: " << name << endl;    
cout << "After reverse: " << reverse(name) << endl;
    
    
    
    return 0;
}
