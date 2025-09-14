#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string input;
    cin >> input;
    stack<char>brackets;
    bool validation = true;
    for(int i=0; i<input.size(); i++){
        char c = input[i];
        if(c=='(' || c=='{' || c=='['){
            brackets.push(c);
        }else{
            if(brackets.empty()){
                validation = false;
                break;
            }else{
                char top = brackets.top();
                if(c==')' && top=='(' || c=='}' && top=='{' || c==']' && top=='['){
                    brackets.pop();
                }else{
                    validation = false;
                    break;
                }
                
            }
        }
        
        
    }
    if(!brackets.empty()) validation = false;
    cout << (validation ? "true" : "false") << endl;
    
    
    
    return 0;
}
