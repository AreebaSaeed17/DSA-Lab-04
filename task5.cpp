#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

// implementing the singly linkedlist

class SinglyLinkedList {

public:
    struct node {
        
        int data;
        node* next = nullptr;
        node(int data) {

        }
        };

    node* head = nullptr;

    void insertEnd(int val) {
        node* n1 = new node(val);
        if (head == nullptr) {
            head = n1;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = n1;
        }
    }

    // Operations

    // next
    node* next(node* curr) {
        if (curr == nullptr) return nullptr;
        return curr->next;
    }

    // Previous
    node* previous(node* curr) {
        if (curr == nullptr || curr == head) return nullptr;
        node* temp = head;
        while (temp != nullptr && temp->next != curr) {
            temp = temp->next;
        }
        return temp;
    }

    // InsertAfter
    void insertAfter(node* curr, int val) {
        if (curr == nullptr) return;
        node* newNode = new node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    //  InsertBefore 
    void insertBefore(node* curr, int val) {
        if (curr == nullptr) return;
        if (curr == head) {
            node* newNode = new node(val);
            newNode->next = head;
            head = newNode;
            return;
        }
        node* prev = previous(curr);
        if (prev != nullptr) {
            node* newNode = new node(val);
            newNode->next = curr;
            prev->next = newNode;
        }
    }

    // Delete 
    void Delete_node(node* curr) {
        if (curr == nullptr) return;
        if (curr == head) {
            head = head->next;
            delete curr;
            return;
        }
        node* prev = previous(curr);
        if (prev != nullptr) {
            prev->next = curr->next;
            delete curr;
        }
    }
};

// doubly linkedlist implementation
class DoublyLinkedList {

public:
    struct node {
        int data;
        node* next = nullptr;
        node* prev = nullptr;
       node(int data) {
        this->data = data;
        }
    };

    node* head = nullptr;

    void insertEnd(int val) {
        node* n1 = new node(val);
        if (head == nullptr) {
            head = n1;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = n1;
            n1->prev = temp;
        }
    }

    // Operations

    // next
    node* next(node* curr) {
        if (curr == nullptr){
             return nullptr;
            }
        return curr->next;
    }

    // Previous
    node* previous(node* curr) {
        if (curr == nullptr) {
             return nullptr;
        }
        return curr->prev;
    }

    // InsertAfter
    void insertAfter(node* curr, int val) {
        if (curr == nullptr) {
            return;}
        node* newNode = new node(val);
        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
    }

    // InsertBefore
    void insertBefore(node* curr, int val) {
        if (curr == nullptr){ 
            return;  }
        node* newNode = new node(val);
        newNode->next = curr;
        newNode->prev = curr->prev;
        if (curr->prev != nullptr) {
            curr->prev->next = newNode;
        } else {
            head = newNode;
        }
        curr->prev = newNode;
    }

    // Delete
    void Delete_node(node* curr) {
        if (curr == nullptr) return;
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        } else {
            head = curr->next;
        }
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }
        delete curr;
    }
};


// main body
int main() {

    srand(time(NULL));

    SinglyLinkedList sll;
    DoublyLinkedList dll;
    int numNodes = 50000;

    // giving both the lists identical random data
    for (int i = 0; i < numNodes; i++) {
        int val = rand();
        sll.insertEnd(val);
        dll.insertEnd(val);
    }

    // Pick a target node in the middle 
    int targetIndex = 25000;
    SinglyLinkedList::node* sll_curr = sll.head;
    DoublyLinkedList::node* dll_curr = dll.head;

    for (int i = 0; i < targetIndex; i++) {
        sll_curr = sll_curr->next;
        dll_curr = dll_curr->next;
    }

    cout << fixed << setprecision(6);
    cout << "=========================================================\n";
    cout << " (N = " << numNodes << " nodes)\n";
    cout << " Target: Node at position " << targetIndex << "\n";
    cout << "=========================================================\n\n";

    // recording time for running of code for singly ll
    auto start = high_resolution_clock::now();
    sll.next(sll_curr);
    auto end = high_resolution_clock::now();
    double sll_next_time = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    sll.previous(sll_curr);
    end = high_resolution_clock::now();
    double sll_prev_time = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    sll.insertAfter(sll_curr, 9999);
    end = high_resolution_clock::now();
    double sll_insertAfter_time = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    sll.insertBefore(sll_curr, 8888);
    end = high_resolution_clock::now();
    double sll_insertBefore_time = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    sll.Delete_node(sll_curr);
    end = high_resolution_clock::now();
    double sll_delete_time = duration<double, milli>(end - start).count();

    // timings for doubly linkedlist
    start = high_resolution_clock::now();
    dll.next(dll_curr);
    end = high_resolution_clock::now();
    double dll_next_time = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    dll.previous(dll_curr);
    end = high_resolution_clock::now();
    double dll_prev_time = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    dll.insertAfter(dll_curr, 9999);
    end = high_resolution_clock::now();
    double dll_insertAfter_time = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    dll.insertBefore(dll_curr, 8888);
    end = high_resolution_clock::now();
    double dll_insertBefore_time = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    dll.Delete_node(dll_curr);
    end = high_resolution_clock::now();
    double dll_delete_time = duration<double, milli>(end - start).count();

    // comparison of timings upto 15 digits
    cout << left << setw(15) << "Operation" 
         << setw(25) << "SinglyLinkedList (ms)" 
         << setw(25) << "DoublyLinkedList (ms)" << endl;
    cout << "---------------------------------------------------------\n";
    cout << setw(15) << "Next" << setw(25) << sll_next_time << setw(25) << dll_next_time << endl;
    cout << setw(15) << "Previous" << setw(25) << sll_prev_time << setw(25) << dll_prev_time << endl;
    cout << setw(15) << "InsertAfter" << setw(25) << sll_insertAfter_time << setw(25) << dll_insertAfter_time << endl;
    cout << setw(15) << "InsertBefore" << setw(25) << sll_insertBefore_time << setw(25) << dll_insertBefore_time << endl;
    cout << setw(15) << "Delete" << setw(25) << sll_delete_time << setw(25) << dll_delete_time << endl;

    return 0;
}