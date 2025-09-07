#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node* previous;
    Node(int a) :val(a), next(nullptr), previous(nullptr) {}
};

class dll {
    Node* head;
    Node* current;
    public:
    dll() :head(nullptr), current(head) {}
    ~dll() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void append(int val) {
        Node* newnode = new Node(val);
        if (head == nullptr) {
            head = newnode;
            current = head;
            return;
        }
        newnode->previous = current;
        current->next = newnode;
        current = current->next;
    }

    void print() {
        Node* itr = head;
        while (itr) {
            cout << itr->val << "--> ";
            itr = itr->next;
        }
        cout << "null";
    }

    void pop(int target) {
        Node* itr = head;
        while (itr) {
            if (itr -> val == target && itr == head) {
                Node* temp = head;
                head = head -> next;
                delete temp;
            }
            if (itr -> val == target) {
                Node* temp = itr;
                itr->previous->next = itr->next;
                delete temp;
            }
            itr = itr->next;
        }
    }
};

int main() {
    cout << "implementing doubly linkedlist" << endl;
    dll* ll = new dll;

    for (int i = 1; i <=5; i++) 
        ll->append(i);
    
    ll->print();
    cout << endl;

    ll->pop(5);

    ll->print();

    return 0;
}