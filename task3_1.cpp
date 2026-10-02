#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<chrono>

class Linkedlist{
    public:
    public:
    struct node{
        int data;
        node * next = nullptr;

        node(int data){
        this->data = data;
        }
    };
    
    node * head = nullptr;
    node * tail = nullptr;

    // create a linkedlist by adding stuff to the head
    void createLL(int data){
        node* n1 = new node(data);

        if (head == nullptr){
            head = n1;
            tail = n1;
        }

        else{
            tail->next = n1;
            n1->next = nullptr;tail = n1;
        }
    }

};

int main(){

     // seeding the srand
    srand(time(NULL));

    Linkedlist *l = new Linkedlist();

    // create a loop to make a linkedlist with 2000 nodes
    // the data for these would be random numbers
    std::cout<<"_____________Creating the Linkedlist with 2000 nodes_____________\n";
    for(int i =1 ; i<=2000; i++){ 
        l->createLL(rand());
    }

}
