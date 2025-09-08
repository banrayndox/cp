_______________________________________________________________________________________________________________________________Rakib_Biswash_______________________________________________________________________________________________________________________________________


#include <iostream>
using namespace std;
struct node{
    int value;
    node* next;
};
void print(node* &head){
    node* current = head;
    while(current!=nullptr){
        cout << current->value;
        if(current->next!=nullptr) cout << "->";
        else cout << endl;
        current = current->next;
    }
}
void reverse(node* &head){
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;
    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    print(head);
}
int main(){
    node* head = new node{1,nullptr};
    head->next = new node{2,nullptr};
    head->next->next = new node{3,nullptr};
    head->next->next->next = new node{4,nullptr};
    cout << "Before Reverse:" << endl;
    print(head);
    cout << "After Reverse:" << endl;
    reverse(head);
    
    
    return 0;
}
