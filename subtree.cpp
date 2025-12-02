#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* left, * right;
    Node(int value){
        this->value = value;
        left = right = nullptr;
    }
};

bool isIdentical(Node* root1 , Node* root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->value != root2->value) return false;
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* tree, Node* subtree){
    if(!subtree) return true;
    if(!tree) return false;
    if(tree->value == subtree->value){
     if( isIdentical(tree, subtree) ) return true;
    }
    return isSubtree(tree->left, subtree) || isSubtree(tree->right, subtree);
}



int main(){
    
  Node* tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);

    Node* subtree = new Node(2);
    subtree->left = new Node(4);
    subtree->right = new Node(5);

    if(isSubtree(tree, subtree)) {
        cout << "Yes, subtree exists!" << endl;
    } else {
        cout << "No, subtree does not exist." << endl;
    }

    return 0;  
    
    
    
    return 0;
}
