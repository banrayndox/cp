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
Node* root = nullptr;
int idx = 0;
Node* buildTree(vector<int> &array){
    if(idx>=array.size() || array[idx]==-1){
        idx++;
        return nullptr;
    } 
    Node* root = new Node(array[idx++]);
    root->left = buildTree(array);
    root->right = buildTree(array);
    return root;
}
void topView(Node* root){
    queue<pair<Node*, int>> q; // Node, distance
    map<int, int> hdNode; // distance, value
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*, int> top = q.front(); q.pop();
        Node* node = top.first;
        int distance = top.second;
        if(hdNode.count(distance)==0) hdNode[distance] = node->value;
        if(node->left) q.push(make_pair(node->left, distance-1));
        if(node->right) q.push(make_pair(node->right, distance+1));
        
    }
    for(auto x: hdNode){
        cout <<  x.second << " ";
    }
}


void bottomView(Node* root){
    queue<pair<Node*, int>> q; // Node, distance
    map<int, int> hdNode; // distance, value
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*, int> top = q.front(); q.pop();
        Node* node = top.first;
        int distance = top.second;
        hdNode[distance] = node->value;
        if(node->left) q.push(make_pair(node->left, distance-1));
        if(node->right) q.push(make_pair(node->right, distance+1));
        
    }
    for(auto x: hdNode){
        cout <<  x.second << " ";
    }
}

int main(){
    vector<int> array = {5,3,-1,-1,4,-1,2,-1,-1};
    root = buildTree(array);
    topView(root);
    cout << endl;
    bottomView(root);
    return 0;
}
