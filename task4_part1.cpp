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

    // delete the last node

    void delete_LastNode(){
        node *temp = head;
        node *hold = temp;

        while(temp->next->next!= nullptr){
            temp = temp->next;
        }
        // reached 2nd last node
        // hold link for last node
        hold = temp->next;
        delete hold;
        temp->next = nullptr;
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



