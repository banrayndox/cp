#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key, height;
    Node* left, * right;
    Node(int key): key(key), left(nullptr), right(nullptr), height(1){};
};
class AVL_TREE{
    public:
    Node* root;
    AVL_TREE() : root(nullptr){};
    void in_order(Node* root){
        if(!root) return;
        in_order(root->left);
        cout << root->key << ", ";
        in_order(root->right);
    }
    int height(Node* root){
        return root ? root->height : 0;
    }
    int updateHeight(Node* root){
       return 1 + max(height(root->left), height(root->right)); 
    }
    int balanceFactor(Node* root){
        return height(root->left) - height(root->right);
    }
    Node* leftRotation(Node* root){
        Node* rightChild = root->right;
        Node* temp = rightChild->left;
        rightChild->left = root;
        root->right = temp;
        root->height = updateHeight(root);
        rightChild->height = updateHeight(rightChild);
        return rightChild;
    }
    Node* rightRotation(Node* root){
        Node* leftChild = root->left;
        Node* temp = leftChild->right;
        leftChild->right = root;
        root->left = temp;
        root->height = updateHeight(root);
        leftChild->height = updateHeight(leftChild);
        return leftChild;
    }
    Node* insert(Node* root, int key){
        if(!root) return new Node(key);
        else if (root->key > key) root->left = insert(root->left, key);
        else if(root->key < key) root->right = insert(root->right, key);
        root->height = updateHeight(root);
        int bf = balanceFactor(root);
        if( bf > 1 ){
            if(key < root->left->key ){
                // LL
                return rightRotation(root);
            }else{
                // LR
                root->left = leftRotation(root->left);
                return rightRotation(root);
            }
        }else if( bf < -1) {
            if(key > root->right->key){
                return leftRotation(root);
            }else{
                //RL
                root->right = rightRotation(root->right);
                return leftRotation(root);
            }
        }
        return root;
    }
    Node* findMin(Node* root){
        if(!root) return nullptr;
        if(!root->left) return root;
        return findMin(root->left);
    }
    Node* erase(Node* root, int key){
        if(!root) return nullptr;
        if(key > root->key) root->right = erase(root->right, key);
        else if(key < root->key) root->left = erase(root->left, key);
        else {
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if(!root->left || !root->right){
                if(root->left){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }else if(root->right){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
            }
            else{
                Node* successor = findMin(root->right);
                root->key = successor->key;
                root->right = erase(root->right, successor->key);
            }
        }
        root->height = updateHeight(root);
        int bf = balanceFactor(root);
        if(bf > 1){
            if(balanceFactor(root->left) >=0 ){
                // LL
                return rightRotation(root);
            }else{
                // LR
                root->left = leftRotation(root->left);
                return rightRotation(root);
            }
        }else if( bf < -1){
            if(balanceFactor(root->right) <= 0){
                return leftRotation(root);
            }else{
                root->right = rightRotation(root->right);
                return leftRotation(root);
            }
            
        }
        return root;
    }
};
int main(){
    vector<int> array = { 30, 20, 10, 50, 60, 70, 80, 100, 120, 90, 95 };
    AVL_TREE tree;
    for(auto x: array){
        tree.root = tree.insert(tree.root, x);
    }
    cout << "IN_Order: " << endl;
    tree.in_order(tree.root);
    cout << endl;
    tree.erase(tree.root, 100);
    cout << endl << "After deletion :" << endl;
    tree.in_order(tree.root);
    return 0;
}
