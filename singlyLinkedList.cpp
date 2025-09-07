#include <iostream>
using namespace std;

class node {
    public:
    int val;
    node* next;
    node() {
        val =  -1;
        next = nullptr;
    }
    node (int val) {
        this->val = val;
        next = nullptr;
    }
    node (int val, node* next) {
        this->val = val;
        this->next = next;
    }
};

class linkedlist {
    node* head;
    node* current;
    public:

    linkedlist():head(nullptr), current(head) {}
    ~linkedlist () {
        node* curr = head;
        while (curr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void append(int val) {
        node* bin = new node(val);
        if (current) {
            current->next = bin;
            current = current->next;
        }
        else {
            head = bin;
            current = head;
        }
    }
    void print() {
        node* itr = head;
        while (itr) {
            cout << itr->val << "--> ";
            itr = itr->next;
        }
        cout << "null";
    }
    void pop(int target) {
        if(head == nullptr) {
            cout << "nothing to pop from" << endl;
            return;
        }
        if (head -> val == target) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        node* itr = head;
        while (itr && itr->next) {
            if (itr->next->val == target) {
                node* temp = itr->next;
                itr->next = itr->next->next;
                delete temp;
            }
            itr = itr->next;
        }
    }
};

int main() {
    cout << "implementing linked list" << endl;
    
    linkedlist* list = new linkedlist;
    int i = 1;
    while(i <= 5) {list->append(i); i++;}
    list->print();
    cout << endl;
    list->pop(5);
    list->print();

    return 0;
}