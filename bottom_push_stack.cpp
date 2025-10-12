// all three methods here
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;


void recursion(stack<int>& temp, int value){
    if(temp.empty()){
        temp.push(value);
        return;
    }
    int top = temp.top();
    temp.pop();
    recursion(temp, value);
    temp.push(top);
}

void another_stack(stack<int>& temp, int value){
    stack<int> temp2;
    while(!temp.empty()){
        temp2.push(temp.top());
        temp.pop();
    }
    temp.push(value);
    while(!temp2.empty()){
        temp.push(temp2.top());
        temp2.pop();
    }
}

void vector_method(stack<int>& temp, int value){
    vector<int> temp2;
    while(!temp.empty()){
        temp2.push_back(temp.top());
        temp.pop();
    }
    temp.push(value);
    int lastIndex = temp2.size()-1;
    for(int i = lastIndex; i>=0; i--){
        temp.push(temp2[i]);
    }
}

int main(){
stack <int> first;    
first.push(1);
first.push(2);
first.push(3);
stack <int> temp = first;
while(!temp.empty()){
    cout << temp.top() << " ";
    temp.pop();
}    
cout << endl;
int value = 4;
recursion(first,value);
int value2 = 5;
another_stack(first,value2);
int value3=6;
vector_method(first,value3);
while(!first.empty()){
    cout << first.top() << " ";
    first.pop();
}
    return 0;
}
