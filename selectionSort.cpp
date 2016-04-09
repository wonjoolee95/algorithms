//
//  selectionSort.cpp
//
//  Created by Won J. Lee on 4/8/16.
//
//

#include <iostream>
using namespace std;


void selectionSort(int int_array[], int size) {
    int temp, curr_index, min_index=0;
    for (int i=0; i < size-1; ++i) {
        curr_index = i;
        for (int j=i+1; j < size; ++j) {
            if (int_array[j] < int_array[min_index])
                min_index = j;
        }
        temp = int_array[curr_index];
        int_array[i] = int_array[min_index];
        int_array[min_index] = temp;
    }
}


void printArray(int int_array[], int size) {
    
    for (int i=0; i < size; ++i)
        cout << int_array[i] << ' ';
}


int main(int argc, const char * argv[]) {
    
    int my_array[] = {9, 24, 7, 25, 38, 1, 33, 16, 15, 44, 6, 13, 
    40, 34, 50, 49, 35, 17, 31, 27, 2, 12, 14, 39, 23, 11, 28, 41, 
    47, 37, 3, 43, 48, 32, 20, 21, 42, 46, 45, 22, 18, 29, 8, 19, 
    26, 10, 30, 5, 4, 36}; // a shuffled int array between [1, 50];
    cout << "Initial array: " << endl;
    cout << "  ";
    printArray(my_array, sizeof(my_array)/sizeof(my_array[0]));
    selectionSort(my_array, sizeof(my_array)/sizeof(my_array[0]));
    cout << "\n\n";
    cout << "After insertion sort: " << endl;
    cout << "  ";
    printArray(my_array, sizeof(my_array)/sizeof(my_array[0]));
    cout << "\n\n";
    return 0;
}
