#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<chrono>

class Linkedlist{
    public:
    struct node{
        int data;
        node * next = nullptr;

        node(int data){
        this->data = data;
        }
    };
    
    // only head is available
    node *head = nullptr;

    // create a linkedlist by adding stuff to the head
    void createLL(int data){
        node* n1 = new node(data);

        if (head == nullptr){
            head = n1;
        } else {
            node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = n1; // Attach at the end of the list
        }
}

    
    int countNodes(){

        int num = 0;
        node * count = head;
        while(count!= nullptr){    
            num++;
            count = count->next;
        }
        return num;
    }

   

    // this method deletes node by only using head ptr 
    void deleteNode_byPos(int pos) {
        int size = countNodes();
            if (pos < 0 || pos >= size || head == nullptr) return;

            // edge case deleting the head node
            if (pos == 0) {
                    node *temp = head;
                    head = head->next;
                    delete temp;
                    return;
            }

            // Traverse to the node right before the target node (pos - 1)
            node *prev = head;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }

            node *temp = prev->next;
            prev->next = temp->next;
            delete temp;
        }

    void deleteNode_byPointers(node *prev, node *curr) {
        if (curr == nullptr) return;

        // deleting the head node
        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        delete curr;
    }

    // helper function for deleting nodes with 2 ptrs available
    bool findPointers(int targetValue, node* &prev, node* &curr) {
        prev = nullptr;
        curr = head;

        while (curr != nullptr && curr->data != targetValue) {
            prev = curr;
            curr = curr->next;
        }

        // Returns true if the node was found in the list
        return (curr != nullptr);
    }

};

int main(){
    // seeding the rand
    srand(time(NULL));

    // object of linkedlist class
    Linkedlist *l = new Linkedlist();

    std::cout << "_____________Creating the Linkedlist with 4000000 nodes_____________\n";
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i = 1; i <= 4000000; i++){ 
        l->createLL(rand());
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "Code running time for creating the linkedlist with 4000000 nodes is = " 
              << std::chrono::duration<double, std::milli>(end1 - start1).count() << " ms.\n\n";

   
    // part 1: Delete node by passing position index
  
    auto start_pos = std::chrono::high_resolution_clock::now();
    
    l->deleteNode_byPos(3800);
    
    auto end_pos = std::chrono::high_resolution_clock::now();
    std::cout << "Time for deleting node by passing position: " 
              << std::chrono::duration<double, std::milli>(end_pos - start_pos).count() << " ms.\n\n";


    // part b: deleting node by 2 ptrs by passing its value

    int targetVal = 12345;          // randomly assumed value
    Linkedlist::node *prevPtr = nullptr;
    Linkedlist::node *currPtr = nullptr;

    auto start2 = std::chrono::high_resolution_clock::now();

    if (l->findPointers(targetVal, prevPtr, currPtr)) {
    l->deleteNode_byPointers(prevPtr, currPtr);

    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "Time for deleteNode_byPointers: " 
              << std::chrono::duration<double, std::milli>(end2 - start2).count() << " ms.\n";
    }

    else{
        auto start3 = std::chrono::high_resolution_clock::now();
        std::cout<<"This value wasnt found in any of the linked list nodes.\n";
        auto end3 = std::chrono::high_resolution_clock::now();
        std::cout << "Time spent: " 
              << std::chrono::duration<double, std::milli>(end3 - start3).count() << " ms.\n";
    }

}


