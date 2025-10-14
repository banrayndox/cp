// edge case's are not added

#include <iostream>
using namespace std;
#include <stack>

class qUsingS{
  stack<int> s1;
  stack<int> s2;
  public:
  void push(int n){
      while(!s1.empty()){
          int top = s1.top();
          s1.pop();
          s2.push(top);
      }
      s1.push(n);
      while(!s2.empty()){
          int top = s2.top();
          s2.pop();
          s1.push(top);
      }
  }
  void pop(){
      s1.pop();
  }
  int top(){
      return s1.top();
  }
  void display(){
      while(!s1.empty()){
          cout << s1.top() << endl;
          s1.pop();
      }
  }
    
};

int main(){
    qUsingS Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
 
    Q.display();
    
    
    return 0;
}
