#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

int index = 0;

// Build tree from preorder array with -1 as NULL
Node* build_tree(const vector<int>& array) {
    if (index >= array.size() || array[index] == -1) {
        index++;
        return nullptr;
    }

    Node* root = new Node(array[index++]);
    root->left = build_tree(array);
    root->right = build_tree(array);
    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

// Postorder traversal
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

// Level order traversal
void level_order(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->value << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// Height of tree
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Count of nodes
int count_nodes(Node* root) {
    if (!root) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// Sum of nodes
int sum_nodes(Node* root) {
    if (!root) return 0;
    return root->value + sum_nodes(root->left) + sum_nodes(root->right);
}

// Diameter of tree (O(n^2))
int diameter(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(lh + rh + 1, max(ld, rd));
}

int main() {
    vector<int> array = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = build_tree(array);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    level_order(root);
    cout << endl;

    cout << "Height of Tree: " << height(root) << endl;
    cout << "Count of Nodes: " << count_nodes(root) << endl;
    cout << "Sum of Nodes: " << sum_nodes(root) << endl;
    cout << "Diameter of Tree: " << diameter(root) << endl;

    return 0;
}
