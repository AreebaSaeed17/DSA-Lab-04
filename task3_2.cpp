#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<chrono>


int main(){

    srand(time(nullptr));
    // creating the array on heap with size 2000
    std::cout<<"_______Creating an array with 2000 elements_______\n";
    int *array = new int[2000];
    // initializing array with random elements
    std::cout<<"Initializing the array...\n";
    for(int i = 0; i<2000; i++){
        array[i] = rand();
    }

}