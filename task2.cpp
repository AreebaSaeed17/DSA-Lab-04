#include<iostream>
#include<cstdlib>
#include<ctime>

class Linkedlist{
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
            n1->next = nullptr;
            tail = n1;
        }
        else{
            head->next = n1;
            n1->next = nullptr;
            tail = n1;
        }
    }

    // finding the first, middle and last node of the linkedlist
    node *FirstNode(){
        return head;
    }

    node *MiddleNode(){
        node *fast = head;
        node *slow = head;
        
        // by the end of this loop, slow ptr will be at the middle and the fast ptr will be at null 
        while(fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    node *EndNode(){
        return tail;
    }
    
};

int main(){

    std::clock_t start = clock();

    std::cout << "Time before creation of linkedlist: " << start;

    // seeding the srand
    srand(time(NULL));

    Linkedlist *l = new Linkedlist();

    // create a loop to make a linkedlist with 1000 nodes
    // the data for these would be random numbers
    for(int i =1 ; i<=1000000; i++){
        l->createLL(rand());
    }

    std::clock_t end = clock();

    std::cout << "Time after creation of linkedlist: " << end;

}
