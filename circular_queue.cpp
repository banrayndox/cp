#include <iostream>
using namespace std;
class circularQueue{
    int* arr;
    int capacity;
    int size;
    int front;
    int rear;
  public:
    circularQueue(int n) : arr(new int[n]), capacity(n), size(0), front(0), rear(-1){};
    void push(int x){
        if(isFull()){
            cout << "Queue is Full!" << endl;
            return;
        }
        
        rear = ( rear+1 ) % capacity;
        arr[rear] = x;
        size++;
    }
    void pop(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        
        front = ( front+1 ) % capacity;
        size--;
        if(size==0){
            front = 0;
            rear = -1;
        }
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == capacity;
    }
    int frontValue(){
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return arr[front];
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        int i = front;
        while(true){
            cout << arr[i] << " ";
            if(i==rear) break;
            i = (i+1)%capacity;
        }
        cout << endl;
    }
};

int main(){
    
    circularQueue A(5);
    A.push(5);
    A.push(4);
    A.push(3);
    A.push(2);
    A.pop();
    A.pop();
    A.push(9);
    A.display();
    return 0;
}

