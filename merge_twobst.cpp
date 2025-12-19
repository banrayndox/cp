#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key;
    Node* left, * right;
    Node(int key) : key(key), left(nullptr), right(nullptr){};
};
Node* root = nullptr;
void in_order(Node* root, vector<int>& result){
    if(!root) return;
    in_order(root->left, result);
    result.push_back(root->key);
    in_order(root->right, result);
}
void display(Node* root){
    if(!root) return;
    display(root->left);
    cout << root->key << "->";
    display(root->right);
}
Node* BTA(vector<int> &result, int st, int end){
    if(st > end) return nullptr;
    int mid = ( (end - st) / 2 ) + st;
    Node* temp = new Node(result[mid]);
    temp->left = BTA(result, st, mid-1);
    temp->right = BTA(result, mid+1, end);
    return temp;
}
void merge(Node* root1, Node* root2, vector<int> &result){
    in_order(root1, result);
    in_order(root2, result);
    sort(result.begin(), result.end());
    root = BTA(result, 0, result.size()-1);
    display(root);
}


int main(){
    vector<int> result;
     Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(15);

    Node* root2 = new Node(12);
    root2->left = new Node(8);
    root2->right = new Node(20);

    merge(root1, root2, result);
 
    
    return 0;
}
