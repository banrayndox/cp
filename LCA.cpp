#include <bits/stdc++.h>
using namespace std;
bool rootToPath(Node* root, int n, vector<int> &path){
    if(!root) return false;
    path.push_back(root->value);
    if(n==root->value) return true;
    bool isLeft = rootToPath(root->left, n, path);
    bool isRight = rootToPath(root->right, n, path);
    if(isLeft || isRight) return true;
    path.pop_back();
    return false;
}
int LCA(Node* root, int n1, int n2){
    vector<int> path1;
    vector<int> path2;
    bool isLeft = rootToPath(root, n1, path1);
    bool isRight = rootToPath(root, n2, path2);
    if(!isLeft || !isRight) return -1;
    int idx = -1;
    int i,j; i = j = 0;
    while(i < path1.size() && j < path2.size()){
        if(path1[i]!=path2[j]) return idx;
        idx = path1[i];
        i++; j++;
    }
    return idx;
}
Node* LCA2(Node* root, int n1, int n2){
    if(!root) return nullptr;
    if(root->value == n1 || root->value == n2) return root;
    Node* left = LCA2(root->left, n1, n2);
    Node* right = LCA2(root->right, n1,n2);
    if(!left && !right) return nullptr;
    if(left && right) return root;
    return left ? left : right;
}
int distance(Node* LCA, int n){
    if(!LCA) return -1;
    if(LCA->value == n){
        return 0;
    }
    int left = distance(LCA->left, n);
    int right = distance(LCA->right, n);
    if(left!=-1){
        return left+1;
    }
    if(right!=-1){
        return right+1;
    }
    return -1;
}
int minDis_nodes(Node* root, int n1, int n2){
 Node* LCA = LCA(root, n1, n2);
    int left = distance(LCA, n1);
    int right = distance(LCA, n2);
    return left + right;
}
int kth_ancestor(Node* root, int node, int k){
    // better to do with Node* return type - practice another time
    if(!root) return -1;
    if(root->value == node) return 0;
    int left = kth_ancestor(root->left, node, k);
    int right = kth_ancestor(root->right, node, k);
    if(left == -1 && right == -1) return -1;
    int v = left == -1 ? right : left;
    if(v+1==k){
        cout << root->data << endl;
    }
    return v+1;
    
}
int transform_to_sum_tree(Node* root){
    if(!root) return 0;
    int old_value = root->value;
    int left = transform_to_sum_tree(root->left);
    int right = transform_to_sum_tree(root->right);
    root->value = left + right;
    return old_value + root->value;
}
int main(){
    
    return 0;
}
