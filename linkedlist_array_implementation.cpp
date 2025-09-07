_____________________________________________________________________________________________________________Rakib__Biswash____________________________________________________________________________________________________
#include <iostream>
using namespace std;
struct node{
    int value;
    int next;
};
const int SIZE = 100;
int head = -1;
int freespace = 0;
node nodes[SIZE];
void insert(int n){
    if(freespace>=SIZE){
        cout << "Storage full bro" << endl;
        return;
    }
    nodes[freespace].value = n;
    nodes[freespace].next = -1;
    if(head == -1){
        head = 0;
    }else{
        int current = head;
        while(nodes[current].next != -1){
            current = nodes[current].next;
        }
        nodes[current].next = freespace;
    }
    freespace++;
}
void print(){
    int current = head;
    while(current != -1){
        cout << nodes[current].value << endl;
        current = nodes[current].next;
    }
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    
    print();
    
}
