✅ 1. DOUBLY LINKED LIST (DLL)
📌 Theory (Short & Accurate)
Q1: What is a Doubly Linked List?

A Doubly Linked List is a linear data structure where each node contains three parts:

Data

Pointer to the previous node (prev)

Pointer to the next node (next)

This allows two-way traversal.

Q2: Advantages of Doubly Linked List?

Can traverse forward & backward

Easy deletion of a given node (no need to track previous manually)

Insertion before/after any node is easier than singly linked list

Q3: Disadvantages of DLL?

Takes extra memory because of prev pointer

Operations slightly slower (updating two pointers)

Complex implementation compared to singly linked list

Q4: Applications of DLL

Music playlist (next/previous)

Browser navigation history

Undo/redo operations

Tree, graph adjacency list representation

Q5: Operations on DLL

Insert at head

Insert at tail

Insert at specific index

Delete head

Delete tail

Delete specific value

Traverse forward

Traverse backward

✔️ ESSENTIAL C++ CODE (Doubly Linked List All-in-One)
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deleteHead() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteTail() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    void displayForward() {
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* t = tail;
        while (t) {
            cout << t->data << " ";
            t = t->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyList dl;
    dl.insertHead(10);
    dl.insertHead(20);
    dl.insertTail(5);
    dl.insertTail(1);

    dl.displayForward();
    dl.displayBackward();

    dl.deleteHead();
    dl.deleteTail();

    dl.displayForward();
}

✅ 2. TREE (Binary Tree / General Concepts)
📌 Theory (Short & Easy)
Q1: What is a Tree?

A Tree is a non-linear hierarchical data structure consisting of nodes connected by edges.
It starts with a root node.

Q2: Why use Trees?

Efficient searching (BST)

Hierarchical representation

Used in compilers, file systems, databases

Faster insertion/deletion compared to arrays

Q3: Important Terms

Root → Top node

Parent / Child → Relation

Leaf node → No children

Height → Longest path from root to leaf

Depth → Distance from root

Subtree → Smaller tree inside a big tree

Q4: Types of Trees

Binary Tree → Max 2 children

Binary Search Tree (BST) → Left < Root < Right

AVL Tree → Height-balanced

Heap → Complete binary tree (min/max priority)

Trie → String searching tree

Segment tree → Range query

Q5: Applications of Trees

File directory structure

Syntax tree in compilers

Databases use B-Tree & B+ Tree

Routing (network tree)

AI Min-Max tree

✔️ ESSENTIAL C++ CODE (Binary Tree Basics)
1. Create Tree + Traversals (DFS)
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Traversals
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // create tree manually
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
}

✔️ 2. Binary Search Tree (Insert + Search)
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);

    return root;
}

bool searchBST(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;

    if (key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}
