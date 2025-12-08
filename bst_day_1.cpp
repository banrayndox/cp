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
Node* insert(Node* root, int value){
    if(!root) {
        return new Node(value);
    }
    if(value > root->value) insert(root->right, value);
    else insert(root->left, value);
    return root;
}
bool search(Node* root, int value){
    if(!root) return false;
    if(root->value = value) return  true;
    if(value > root->value) return search(root->right, value);
    else return search(root->left, value);
}
Node* successor(Node* root, int value){
    if(!root) return nullptr;
    while(root && root->left){
        root = root->left;
    }
    return root;
}
Node* delete(Node* root, int value){
    if(!root) return nullptr;
    if(root->value < key){
        root->right = delete(root->right, key);
    }else if(root->value > key){
        root->left = delete(root->left, key);
    }else{
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }else if(!root->left || !root->right){
            if(root->left){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else Node* temp = root->right;
            delete root;
            return temp;
        }
        Node* succ = successor(root->right);
        root->value = succ->value;
        root->right = delete(root->right, succ->value);
    }
    return root;
    
}

int minimum(Node* root){
    if(!root) return -1;
    if(!root->left) return root->value;
    return minimum(root->left);
}

int maximum(Node* root){
    if(!root) return -1;
    if(!root->right) return root->value;
    return maximum(root->right);
}
l
void kth_level(Node* root, int level){
    queue<Node*> array;
    array.push(root);
    int count = 1;
    while(!array.empty()){
        int size = array.size();
        if(count==level){
            while(size--){
                cout << array.front()->value << " ";
                array.pop();

            }
        return;
        }
        while(size--){
        Node* top = array.front();
        array.pop();
        if(top->left) array.push(top->left);
        if(top->right) array.push(top->right);
        }
        count++;
    }
    
}  
void print_range(Node* root, int start, int end){
    if(!root) return;
    if(root->data > start) print_range(root->left, start, end);
    if(start >= root->value && end >= root->value ) cout << root->value  << " ";
    if(root->data < end) print_range(root->right, start, end);
}
void print_kth_rec(Node* root, int level){
    if(!root) return;
    if(level==1) {
        cout << root->value << " ";
        return;
    }
    print_kth_rec(root->left, level-1);
    print_kth_rec(root->right, level-1);
}
void print_leaf_path(Node* root, vector<int> &path){
    if(!root) return;
    path.push_back(root->value);
    if(!root->left && !root->right){
        for(auto x: path){
            cout << x << " ";
        }
        cout << endl;
    }
    print_leaf_path(root->left, path);
    print_leaf_path(root->right, path);
    path.pop_back();
}
bool validate_helper(Node* root, Node* min, Node* max){
    if(!root) return true;
    if((min && root->value <= min->value ) || (max && root->value >= max->value)) return false;
    return validate_helper(root->left,min,root) && validate_helper(root->right,root,max);
}
bool bst(Node* root){
    return validate_helper(root,nullptr,nullptr);
}
int main(){
    
    
    
    
    
    
    return 0;
}
