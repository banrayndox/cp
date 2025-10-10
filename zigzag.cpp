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
    int s;

    List() : head(nullptr), tail(nullptr), s(0){};
    int size(){
        return s;
    }
    void print(){
        Node* curr = head;
        while(curr){
            cout << curr->value;
            (curr->next) ? (cout <<"->") : (cout<<endl);
            curr = curr->next;
        }
    }
    void push_back(int x){
        Node* newNode = new Node(x);
        if(tail==nullptr){
            head=tail=newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        s++;
    }
    Node* get_mid(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* head){
        if(!head || !head->next) return head;
        Node* mid = get_mid(head);
        Node* l = head;
        Node* r = mid->next;
        mid->next = nullptr;
        Node* left = merge(l);
        Node* right = merge(r);
        return merge_sort(left, right);
    }
    Node* merge_sort(Node* left, Node* right){
        Node* i = left;
        Node* j = right;
        List temp;
        while(i && j){
            if(i->value<j->value){
                temp.push_back(i->value);
                i = i->next;
            }else{
                temp.push_back(j->value);
                j = j->next;
            }
        }
        
        while(i){
            temp.push_back(i->value);
                i = i->next;
        }
        while(j){
            temp.push_back(j->value);
                j = j->next;
        }
        return temp.head;
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
        return head = prev;
    }
  Node* zigzag(Node* head){
      if(!head || !head->next) return head;
      Node* left = head; // LEFT
      Node* mid = get_mid(head);
      Node* r = mid->next; // RIGHT
      mid->next = nullptr;
      Node* right = reverse(r);
      Node* tail = right; // TAIL
      int count = 0;
      while(left && right){
          count++;
        Node*  nextleft = left->next;
        Node*  nextRight = right->next;
          left->next = right;
          right->next = nextleft;
          left = nextleft;
          tail = right;
          right = nextRight;
      }

      if(right) tail->next = right;
      return head;
  }
};

int main(){
    
    List L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.print();
    L.head = L.zigzag(L.head);
    L.print();
    return 0;
}
