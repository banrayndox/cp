#include <iostream>
using namespace std;
class Node{
  public:
  int value;
  Node* next,* prev;
  Node(int x) : value(x), next(nullptr), prev(nullptr){};
};
class doublyList{
  public:
  Node* head;
  
  doublyList() : head(nullptr){};
  
  void print(){
      Node* curr = head;
      while(curr){
          cout << curr->value;
          (curr->next) ? (cout << "->") : (cout << endl);
          curr = curr->next;
      }
  }
  void push_front(int x){
      Node* newNode = new Node(x);
      if(head){
          head->prev = newNode;
      }
      newNode->next = head;
      head = newNode;
  }
  void pop_front(){
   if(!head) {
       cout << "Node doesn't exists!" << endl;
       return;
   }  
   Node* temp = head;
   head = head->next;
   if(head) head->prev = nullptr;
   delete temp;
  }

};
int main(){
    doublyList L;
    L.push_front(5);
    L.push_front(4);
    L.push_front(3);
    L.print();
    return 0;
}
