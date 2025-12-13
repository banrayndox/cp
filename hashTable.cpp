#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  string key;
  int value;
  Node* next;
  Node(string key, int value){
      this->key = key;
      this->value = value;
      next = nullptr;
  }
};
class hashTable{
    private:
    int capacity;
    int size;
    Node** table;
    int hashing(string key){
        int hash = 0;
        for(int ch: key){
            hash += ch;
        }
        return hash % capacity;
    }
    void reHashing(){
        int oldCapacity = capacity;
        capacity *= 2;
        Node** oldTable = table;
        table = new Node*[capacity]();
        for(int i=0; i<oldCapacity; i++){
            Node* temp = oldTable[i];
            while(temp){
                insert(temp->key, temp->value);
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] oldTable;
    }
    public:
        hashTable(int cap = 5){
        size = 0;
        capacity = cap;
        table = new Node*[capacity]();
    }
    ~hashTable(){
        for(int i=0; i<capacity; i++){
            Node* temp = table[i];
            while(temp){
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] table;
    }
    void insert(string key, int value){
        int index = hashing(key);
        // if exists the key then update
        Node* temp = table[index];
        while(temp){
            if(temp->key == key){
                temp->value = value;
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        size++;
        float loadFactor = (double)size / (double)capacity;
        if(loadFactor > 1.00) reHashing();
    }
    bool search(string key){
        int index = hashing(key);
        Node* temp = table[index];
        while(temp){
            if(temp->key == key) return true;
            temp = temp->next;
        }
        return false;
    }
    bool del(string key){
        int index = hashing(key);
        Node* temp = table[index];
        Node* prev = nullptr;
        while(temp){
            if(temp->key == key){
              if(!prev)  table[index] = temp->next; 
              if(prev)   prev->next = temp->next;
              delete temp;
              size--;
              return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
        
        
    }
    void display(){
        for(int i=0; i<capacity; i++){
            Node* temp = table[i];
            while(temp){
                cout << "( " << temp->key << " : " << temp->value << " )" << endl;
                temp = temp->next;
            }
        }
    }
};
int main(){
    hashTable banx(5);
    banx.insert("BD", 880);
    banx.insert("IND", 91);
    banx.insert("US", 1);
    banx.display();
    cout << banx.del("US") << endl;
    banx.display();
     cout << banx.search("IND") << endl;
     cout << banx.search("US") << endl;
    
    
    return 0;
}
