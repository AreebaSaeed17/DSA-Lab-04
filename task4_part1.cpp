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
        }

        else{
            node *temp = head;
            while(temp->next!=nullptr){
                temp->next = n1;
                n1->next = nullptr;
                temp = temp->next;
            }

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

   

        void deleteNode_byPos(int pos) {
        int size = countNodes(); 

        if (pos < 0 || pos >= size || head == nullptr) {
            return;
        }

        // if head has to be deleted
        if (pos == 0) {
            node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // delete any specific node
        node *prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }

        node *temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }


};

int main(){

     // seeding the srand
    srand(time(NULL));

    Linkedlist *l = new Linkedlist();

    // create a loop to make a linkedlist with 40 nodes
    // the data for these would be random numbers
    std::cout<<"_____________Creating the Linkedlist with 40 nodes_____________\n";
    for(int i =1 ; i<=40; i++){ 
        l->createLL(rand());
    }
}



