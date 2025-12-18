#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key;
    Node* left, * right;
    int height;
    Node(int key) : key(key), left(nullptr), right(nullptr), height(1){};
};
class AVL_tree{
    public:
    Node* root;
    AVL_tree() : root(nullptr){};
    int height(Node* root){
        return root ? root->height : 0;
    }
    int updateHeight(Node* root){
        return 1 + max(height(root->left), height(root->right));
    }
    int balance(Node* root){
        return height(root->left) - height(root->right);
    }
    // LL case
    Node* rightRotate(Node* root){
        Node* leftChild = root->left;
        Node* T3 = leftChild->right;
        leftChild->right = root;
        root->left = T3;
        root->height = updateHeight(root);
        leftChild->height = updateHeight(leftChild);
        return leftChild;
    }
    // RR case
    Node* leftRotate(Node* root){
        Node* rightChild = root->right;
        Node* T2 = rightChild->left;
        rightChild->left = root;
        root->right = T2;
        root->height = updateHeight(root);
        rightChild->height = updateHeight(rightChild);
        return rightChild; 
    }
    Node* insert(Node* root, int key){
        if(!root) return new Node(key);
        else if(key < root->key) root->left = insert(root->left, key);
        else if(key > root->key) root->right = insert(root->right, key);
        else return root;
        root->height = updateHeight(root);
        int balancef = balance(root);
        if( balancef < -1 ){
            if(key > root->right->key){
                return leftRotate(root);
            }else{
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }else if ( balancef > 1 ){
            if(key < root->left->key) return rightRotate(root);
            else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
                
            }
        }
        return root;
    }
    void display_inOrder(Node* root){
        if(!root) return;
        display_inOrder(root->left);
        cout << root->key << ", ";
        display_inOrder(root->right);
    }
};

int main(){
    vector<int> array = {20,30,30,10,50,60,70};
    AVL_tree Tree;
    for(auto x: array){
       Tree.root = Tree.insert(Tree.root, x);
    }
    Tree.display_inOrder(Tree.root);
}
