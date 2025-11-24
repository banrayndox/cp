#include <bits/stdc++.h>
using namespace std;

// --------------------------
// NODE STRUCTURE
// --------------------------
class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

// --------------------------
// DOUBLY LINKED LIST CLASS
// --------------------------
class DoublyList {
public:
    Node* head;
    Node* tail;
    int sz;

    DoublyList() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    // --------------------------
    // INSERT AT HEAD
    // --------------------------
    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        sz++;
    }

    // --------------------------
    // INSERT AT TAIL
    // --------------------------
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        sz++;
    }

    // --------------------------
    // INSERT AT ANY POSITION
    // pos = index (0-based)
    // --------------------------
    void insertAtPos(int pos, int val) {
        if (pos < 0 || pos > sz) {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 0) {
            insertHead(val);
            return;
        }
        if (pos == sz) {
            insertTail(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 0; i < pos - 1; i++) temp = temp->next;

        Node* after = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        newNode->next = after;
        after->prev = newNode;

        sz++;
    }

    // --------------------------
    // DELETE HEAD
    // --------------------------
    void deleteHead() {
        if (head == nullptr) return;

        Node* delNode = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete delNode;
        sz--;
    }

    // --------------------------
    // DELETE TAIL
    // --------------------------
    void deleteTail() {
        if (tail == nullptr) return;

        Node* delNode = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete delNode;
        sz--;
    }

    // --------------------------
    // DELETE AT ANY POSITION
    // pos = index (0-based)
    // --------------------------
    void deleteAtPos(int pos) {
        if (pos < 0 || pos >= sz) {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 0) {
            deleteHead();
            return;
        }
        if (pos == sz - 1) {
            deleteTail();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos; i++) temp = temp->next;

        Node* before = temp->prev;
        Node* after = temp->next;

        before->next = after;
        after->prev = before;

        delete temp;
        sz--;
    }

    // --------------------------
    // SEARCH VALUE (returns index)
    // --------------------------
    int searchValue(int val) {
        Node* temp = head;
        int idx = 0;
        while (temp) {
            if (temp->value == val) return idx;
            temp = temp->next;
            idx++;
        }
        return -1; // not found
    }

    // --------------------------
    // DISPLAY FORWARD
    // --------------------------
    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // --------------------------
    // DISPLAY BACKWARD
    // --------------------------
    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // --------------------------
    // SIZE
    // --------------------------
    int length() {
        return sz;
    }
};

// --------------------------
// MAIN FUNCTION
// --------------------------
int main() {
    DoublyList dl;

    dl.insertHead(10);
    dl.insertTail(20);
    dl.insertTail(30);
    dl.insertAtPos(1, 15);

    cout << "Forward: ";
    dl.displayForward();

    cout << "Backward: ";
    dl.displayBackward();

    cout << "Length: " << dl.length() << endl;

    cout << "Index of 20: " << dl.searchValue(20) << endl;

    dl.deleteHead();
    dl.deleteTail();
    dl.deleteAtPos(1);

    cout << "After deletions: ";
    dl.displayForward();

    return 0;
}
