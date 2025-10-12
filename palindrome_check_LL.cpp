#include <iostream>
using namespace std;
class Node{
  public:    
  int value;
  Node* next;
  Node(int x) : value(x), next(nullptr){};
};
class List{
    public:
    Node* head;
    Node* tail;
    List() : head(nullptr), tail(nullptr){};
    void push_back(int x){
        Node* newNode = new Node(x);
        if(tail==nullptr){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    Node* find_mid(){
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return  slow;
    }
    Node* reverse(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(){
        if(!head || !head->next ) return true;
        Node* mid = find_mid();
        Node* rev_head = reverse(mid->next);
        Node* first = head;
        Node* second = rev_head;
        while(second){
            if(first->value!=second->value){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};

int main(){
    List L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(5);
    L.push_back(2);
    L.push_back(1);
    ( L.isPalindrome() ) ? (cout<<"Palindrome"<<endl) : (cout<<"Not palindrome"<<endl);
    return 0;
}
