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

     // finding the first, middle and last node of the linkedlist
    node *FirstNode(){
        return head;
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

    node* findNode_Pos_by_value(int data){
        
        int size_LL = countNodes();
        node * temp_find = head;
        int pos = 0;

        for (int i=0; i<size_LL; i++){
            if (temp_find->data == data){
            }
        return temp_find;
        }

    }

    node *EndNode(){
        return tail;
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


     auto start1 = std::chrono::high_resolution_clock::now();
    l->FirstNode();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "Code running time for accessing 1st node is = " << std::chrono::duration<double, std::milli>(end1 -start1).count()<<" ms." << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    l->findNode_Pos_by_value(5678);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "Code running time for finding randomly chosen node is = " << std::chrono::duration<double, std::milli>(end2 -start2).count()<<" ms." << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();;
    l->EndNode();
    auto end3 = std::chrono::high_resolution_clock::now();
    std::cout << "Code running time for accessing last node is = " << std::chrono::duration<double, std::milli>(end3 -start3).count()<<" ms." << std::endl;
}


