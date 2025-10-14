#include <iostream>
using namespace std;
#include <queue>

class sUq{
    queue<int> a,b;
    public:
    void push(int n){
        while(!a.empty()){
            b.push(a.front());
            a.pop();
        }
        a.push(n);
        while(!b.empty()){
            a.push(b.front());
            b.pop();
        }
    }
    int top(){
        return a.front();
    }
    void pop(){
        cout << "test" << endl;
        a.pop();
    }
    void display(){
        queue<int> temp = a;
        while(!temp.empty()){
            cout << temp.front() << "->";
            temp.pop();
        }
        cout << endl;
    }
    
};


int main(){
    sUq S;
    S.push(10);
    S.push(20);
    S.push(30);
    S.display();
    S.pop();
    S.display();
    
    
    
    
    
    return 0;
}
