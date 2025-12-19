#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key;
    Node* left, *right;
    Node(int key) : key(key), left(nullptr), right(nullptr){};
};
Node* root = nullptr;
Node* insert(Node* root, int key){
    if(!root) return new Node(key);
    if(key > root->key) root->right = insert(root->right, key);
    else if(key < root->key) root->left = insert(root->left, key);
    return root;
}
class info{
    public: 
    bool isBST;
    int size;
    int maxValue;
    int minValue;
    Node* address;
    int largestBSTsize;
    info(int isBST = true, int size = 0, int maxValue = INT_MIN, int minValue = INT_MAX, Node* address = nullptr, int largestBSTsize = 0){
        this->isBST = isBST;
        this->size = size;
        this->maxValue = maxValue;
        this->minValue = minValue;
        this->address = address;
        this->largestBSTsize = largestBSTsize;
    }
};
info maxBST(Node* root){
    if(!root) {
        return info(true, 0, INT_MIN, INT_MAX, nullptr, 0);
    }
    info left = maxBST(root->left); 
    info right = maxBST(root->right);
    info curr;
    curr.size = left.size + right.size +1;
    if(left.isBST && right.isBST && left.maxValue < root->key && root->key < right.minValue){
        curr.isBST = true;
        curr.maxValue =  max(root->key, right.maxValue);
        curr.minValue =  min(root->key, left.minValue);
        curr.address = root;
        curr.largestBSTsize = curr.size;
    }else{
        curr.isBST = false;
        if(left.largestBSTsize > right.largestBSTsize){
            curr.address = left.address;
            curr.largestBSTsize = left.largestBSTsize;
        }else{
            curr.address = right.address;
            curr.largestBSTsize = right.largestBSTsize;
        }
    }
    return curr;
}
void display(Node* root){
    if(!root) return;
    display(root->left);
    cout << root->key << "->";
    display(root->right);
}
int main(){
    vector<int> array = {10,20,30,40,50,70,80};
    for(auto x: array){
        root = insert(root, x);
    }
    info result = maxBST(root);
    cout << result.largestBSTsize << endl; 
    return 0;
}
