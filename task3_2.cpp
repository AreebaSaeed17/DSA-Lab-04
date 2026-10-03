#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<chrono>

void search_byVal(int value, int arr[], const int size){
    bool result;
    for (int i=0; i<size; i++){
        if(arr[i] == value){
            std::cout<<"Match found at index: " <<i <<std::endl;
            result;
        }
    }
    if(!result){
        std::cout<<"Not found anywhere in the array.\n";
    }
}

int main(){

    srand(time(nullptr));
    const int size = 2000;
    // creating the array on heap with size 2000
    std::cout<<"_______Creating an array with 2000 elements_______\n";
    int *array = new int[size];
    // initializing array with random elements
    std::cout<<"\nInitializing the array...\n";
    for(int i = 0; i<size; i++){
        array[i] = rand();
    }

  
    // 1st element access time
    auto start1 = std::chrono::high_resolution_clock::now();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "\nCode running time for accessing 1st element = " << std::chrono::duration<double, std::milli>(end1 -start1).count()<<" ms." << std::endl;

    // last element access time
    auto start2 = std::chrono::high_resolution_clock::now();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "\nCode running time for accessing last element = " << std::chrono::duration<double, std::milli>(end2 -start2).count()<<" ms." << std::endl;

    // access kth element eg 778th element
    auto start3 = std::chrono::high_resolution_clock::now();
    auto end3 = std::chrono::high_resolution_clock::now();
    std::cout << "\nCode running time for accessing kth element = " << std::chrono::duration<double, std::milli>(end3 -start3).count()<<" ms." << std::endl;

    //search value
    auto start4 = std::chrono::high_resolution_clock::now();
    search_byVal(45, array, size);
    auto end4 = std::chrono::high_resolution_clock::now();
    std::cout << "\nCode running time for searching a value = " << std::chrono::duration<double, std::milli>(end4 -start4).count()<<" ms." << std::endl;


}