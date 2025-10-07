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
    void display(){
    Node* curr = head;
    while(curr!=nullptr){
        cout << curr->value;
        (curr->next!=nullptr) ? (cout<<"->") : (cout<<endl);
        curr = curr->next;
    }
    }
    length(){
    return s;
    }
    void insert_front(int x){
    Node* newNode = new Node(x);
    if(head==nullptr){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    s++;
    }
    int front_value(){
    if(head==nullptr){
        return -1;
    }else{
    return head->value;
    }

    }
    void delete_front(){
    if(head==nullptr){
        cout << "Node doesn't exists" << endl;
        return;
    }
    if(head->next==nullptr){
    delete head;
    head=nullptr;
    }else{
    Node* temp = head;
    head = head->next;
    delete temp;
    }
    s--;
    }
void insert_back(int x){
    Node* newNode = new Node(x);
if(tail==nullptr){
    head = tail = nullptr;
}else{
tail->next = newNode;
tail = newNode;
}
s++;
}
   int back_value(){
    if(tail==nullptr){
        return -1;
    }else{
    return tail->value;
    }

}
    void delete_back(){
    if(tail==nullptr){
        cout << "Node doesn't exists" << endl;
        return;
    }
Node* curr = head;
while(curr->next->next!=nullptr){
    curr=curr->next;
}
delete curr->next;
curr->next = nullptr;
tail=curr;
    s--;
    }

 void detect_cycle(){
 Node* slow = head;
 Node* fast = head;
 while(fast!=nullptr && fast->next!=nullptr){
    slow = slow->next;
    fast = fast->next->next;
    if(slow==fast) {
        cout<<"Cycle Detected"<<endl;
        return;
    }
 }
 cout << "Cycle Not Detected" << endl;
 }

int helper(Node* head, int target, int index){
if(head==nullptr) return -1;
if(head->value==target) return index;
return helper(head->next, target, index+1);
}
void searchLL(int target){
int x = helper(head, target, 0);
if(x==-1) cout << "Not found" << endl;
else cout <<"Found at: "<< x <<endl;
}
void reverseLL(){
Node* prev = nullptr;
Node* curr = head;
Node* next = nullptr;
tail = curr;
while(curr!=nullptr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
head = prev;

}

};
int main(){
List sujal;
sujal.insert_front(1);
sujal.insert_front(2);
sujal.insert_front(3);
sujal.insert_back(1);
int x = sujal.length();
cout << x << endl;
sujal.display();
sujal.delete_back();
sujal.display();
sujal.detect_cycle();
sujal.searchLL(1);
sujal.reverseLL();
sujal.display();
return 0;
}
