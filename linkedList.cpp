________________________________________________________________________________________________________________________Rakib_Biswash__________________________________________________________________________________________________________________________________________



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
    if(head==nullptr) return;
    reverse(head->next);
    cout << head->value << " ";
}
 void middle(node* &head){
     node* slow = head;
     node* fast = head->next;
     while(fast!=nullptr && fast->next!=nullptr){
         slow = slow->next;
         fast = fast->next->next;
     }
     cout << "Middle index value is :" << slow->value << endl;
 }
int count(node* &head){
    node* current = head;
    int count = 0;
    while(current!=nullptr){
        count++;
        current = current->next;
    }
    return count;
}
void insert_head(node* &head, int val){
    node* newnode = new node{val,nullptr};
    newnode->next = head;
    head = newnode;
    cout << "Head Inserted:" << endl;
    print(head);
}
void insert_tail(node* &head, int val){
    node* newnode = new node{val,nullptr};
    node* current = head;
    while(current->next!=nullptr){
        current=current->next;
    }
    current->next = newnode;
    cout << "Tail inserted:" << endl;
    print(head);
}
void insert_position(node* &head, int value, int position){
    if(head==nullptr) {
        cout << "Invalid Head!" << endl;
        return;
    }
    if(position==1){
        node* newnode = new node{value,nullptr};
        newnode->next = head;
        head = newnode;
    }else{
        int count = 1;
        node* current = head;
        while(count<position-1 && current!=nullptr){
            current = current->next;
            count++;
        }
        if(current==nullptr){
            cout << "Invalid Position" << endl;
            return;
        }else{
            node* newnode = new node{value,nullptr};
            newnode->next = current->next;
            current->next = newnode;
        }
    }
cout << "After insertion Tail: ";
print(head);
}

void index_access(node* &head, int position){
    node* current = head;
    int count = 1;
    while(current!=nullptr &&  count<position){
        // 0 based index - count<position+1
        current = current->next;
        count++;
    }
    
    cout<< position << " - index(1based) Value is: ";
    cout << current->value <<endl;
}

void autoInsertInSortedList(node* &head, int value){
    if(head==nullptr) {
        cout << "Invalid Head!" << endl;
        return;
    }
    node* newnode = new node{value, nullptr};
    if(value<=head->value){
        newnode->next = head;
        head = newnode;
        return;
    }else{
        
    node* current = head;
    while(current->next!=nullptr && current->next->value < value){
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
    cout << "Auto insertion: ";
    print(head);
    return;
    }
}

void delete_head(node* &head){
    node* temp = head;
    head = head->next;
    delete temp;
    cout << "After deletion head: ";
    print(head);
}
void delete_tail(node* &head){
    if(head==nullptr){
        cout << "Invalid Head" << endl;
        return;
    }
    if(head->next==nullptr){
        delete head;
        head = nullptr;
        cout << "Head deleted" <<endl;
        return;
    }
    node* current = head;
    while(current->next->next!=nullptr){
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    cout << "After deletion tail: ";
    print(head);
    
}

void delete_position(node* &head, int position){
    if(head==nullptr) {
        cout << "Invalid Head" << endl;
        return;
    }
    if(position==1){
        node* temp = head;
        head = head->next;
        delete temp;
        cout << "Head deleted by position: " << position << endl;
        print(head);
        return;
    }else{
        int count = 1;
        node* current = head;
        while(count<position-1 && current->next!=nullptr){
            count++;
            current = current->next;
        }
        if(current->next == nullptr) {
            cout << "Invalid Position" <<endl;
            return;
        }
        node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "After deletion by position:";
        print(head);
        return;
        
    }
}

node* findOccur(node* head, int value, int occur){
    if(head==nullptr){
        cout << "Invalid Head" << endl;
        return nullptr;
    }
    node* current = head;
    int count = 0;
    int index = 1;
    while(current!=nullptr){
        if(current->value == value){
            count++;
        }
        if(count == occur) {
            cout << "Found at position: " << index << endl;
            return current;
        }
        current = current->next;
        index++;
    }
    return nullptr;
}

int main(){
    node* head = new node{1,nullptr};
    head->next = new node{2,nullptr};
    head->next->next = new node{3,nullptr};
    head->next->next->next = new node{4,nullptr};
    head->next->next->next->next = new node{5,nullptr};    
    print(head);
    middle(head);
    cout << "Reverse nodelist: ";
    reverse(head);
    cout << endl;
    cout << "Total nodelist: " << count(head)<< endl;
    int head_val = 0;
    int tail_val = 6;
    insert_head(head, head_val);
    insert_tail(head, tail_val);
    int index = 3;
    index_access(head, index);
    int autovalue = 4;
    autoInsertInSortedList(head, autovalue);
    delete_head(head);
    delete_tail(head);
    int del_pos = 4;
    delete_position(head,del_pos);
    int find_value = 4;
    int occur = 1;
    node* resultNode = findOccur(head,find_value,occur);
    if(resultNode==nullptr){
        cout << "Doesn't exists " << occur << "time" << endl;
    }else{
        cout << resultNode->value << " exists on " << resultNode << " " << occur << "time." << endl; 
    }
    return 0;
}
