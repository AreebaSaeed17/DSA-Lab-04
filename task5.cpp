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
        node(int val) : data(val) {

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
    node* Next(node* curr) {
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
    void delete(node* curr) {
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
