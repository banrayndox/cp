#include <iostream>
using namespace std;
class Node{
  public:
  int value;
  Node* next;
  Node(int x) : value(x), next(nullptr){};
};
class List{
  private:
  Node* head;
  Node* tail;
  int s;
  public:
  List(){
      head = tail = nullptr;
      s = 0;
  }
  void push_back(int x){
      Node* newNode = new Node(x);
      if(tail == nullptr){
          head = tail = newNode;
      }else{
          tail->next = newNode;
          tail = newNode;
      }
      s++;
  }
  void display(){
      Node* curr = head;
      while(curr!=nullptr){
          cout << curr->value;
          if(curr->next!=nullptr) cout << "->";
          else cout << endl;
          curr = curr->next;
      }
  }
  int size(){
      return s;
  }
  void detect_cycle(){
      Node* slow = head;
      Node* fast = head;
      while(fast!=nullptr && fast->next!=nullptr){
          slow = slow->next;
          fast = fast->next->next;
          if(fast == slow){
              slow = head;
              while(slow!=fast){
                  slow=slow->next;
                  fast=fast->next;
              }
              Node* temp = slow;
              while(temp->next!=slow){
                  temp = temp->next;
              }
              temp->next = nullptr;
              return;
          }
      }
      
      cout << "Cycle not found" << endl;
  }
  
};
int main(){

}
