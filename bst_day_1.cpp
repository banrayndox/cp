#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* left, *right;
    Node(int value){
        this->value = value;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int value){
    if(root==nullptr) {
        return (new Node(value));
    }
    if(value < root->value){
       root->left = insert(root->left, value);
    }
    else{
      root->right =  insert(root->right, value);
    }
    return root;
    
}
bool search(Node* root, int value){
    if(root==nullptr) return false;
    if(root->value==value) return true;
    if(root->value < value) return search(root->right, value);
    else return search(root->left, value);
}

Node* succedor(Node* root){
    if(root==nullptr) return nullptr;
    while(root && root->left){
        root = root->left;
    }
    return root;
}

Node* node_delete(Node* root, int key){
    if(root == nullptr) return nullptr;
    if(root->value < key) {
        root->right = node_delete(root->right, key);
    }
    else if(root->value > key){
        root->left = node_delete(root->left, key);
    }
    else{
        if(!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else if(!root->left || !root->right){
            if(root->left){
                Node* temp = root->left;
                delete root;
                return temp;
            }else{
                Node* temp = root->right;
                delete root;             
                return temp;
            }
        }
        
        Node* succ = succedor(root->right);
        root->value = succ->value;
        root->right = node_delete(root->right, succ->value);
        
    }
    return root;
}


int main(){
  Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);


    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

    root = node_delete(root, 50); // Delete root node (two children)

    return 0;
}
