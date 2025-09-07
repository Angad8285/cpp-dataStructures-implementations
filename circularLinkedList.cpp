#include <iostream>
using namespace std;

class node {
    public:
    int val;
    node* next;
    node(int val) :val(val), next(nullptr) {}
};

class cll {
    node* head;
    node* current;
    public:
    cll() : head(nullptr) {}
    ~cll() {
        node* itr = head;
        if (!head) return;
        do {
            node* temp = itr;
            itr = itr->next;
            delete temp;
        } while (itr != head);
    }

    void append(int val) {
        node* newnode = new node(val);
        if (head == nullptr) {
            head = newnode;
            current = head;
            current->next = head;
            return;
        }
        current->next = newnode;
        current = current -> next;
        current->next = head;
    }

    void print() {
        node* itr = head;
        do
        {
            cout << itr->val << " -> ";
            itr = itr->next;
        } while (itr != head);
        cout << "head" << endl;
    }

    void pop(int target) {
        if (head == nullptr) {
            cout << "nothing to pop from";
            return;
        }
        if (head->val == target) {
            node* bin = head;
            head = head->next;
            current = head;
            delete bin;
        }

        node* itr = head->next;
        while (itr != head) {
            if (itr->next->val == target) {
                node* bin = itr->next;
                itr->next = itr->next->next;
                delete bin;
            }
            itr = itr->next;
        }
    }
    
    void print(int times) {
        node* itr = head;
        for (int i = 1;i <= times; i++) {
            cout << itr->val << " -> ";
            itr = itr->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "implementing circular Linked List." << endl;
    cll ll;
    for(int i = 1; i <= 5; i++) ll.append(i);
    ll.print();
    ll.pop(5);
    ll.print();
    
    ll.print(8);
    
    return 0;
}