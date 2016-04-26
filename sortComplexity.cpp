//
//  sortComplexity.cpp
//  
//
//  Created by Won J. Lee on 4/9/16.
//
//

#include <iostream>
using namespace std;
#include <cstdio>
#include <ctime>
#include "bubbleAndSelectionSorts.h"



int randomInteger(int max) {
    int random_integer;
    random_integer = (rand()%max)+1;
    return random_integer;
}


int main ()
{
    
{
    int rep_counter = 1000;
    clock_t start;
    double duration;
    
    cout << "Bubble sort complexity:\n";
    while (rep_counter <= 64000) {
        {
        int arr[rep_counter];
            
        for (int i=0; i<rep_counter; ++i)
            arr[i] = randomInteger(rep_counter);
            
        start = clock();
        bubbleSort(arr, rep_counter);
        duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"   Sorting "<< rep_counter << " intergers: " << duration << " sec"<<'\n';
        rep_counter = rep_counter * 2;
        }
    }
}
    
{
    int rep_counter = 1000;
    clock_t start;
    double duration;
    
    cout << "Selection sort complexity:\n";
    while (rep_counter <= 64000) {
        {
            int arr[rep_counter];
            
            for (int i=0; i<rep_counter; ++i)
                arr[i] = randomInteger(rep_counter);
            
            start = clock();
            selectionSort(arr, rep_counter);
            duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
            cout <<"   Sorting "<< rep_counter << " intergers: " << duration << " sec"<<'\n';
            rep_counter = rep_counter * 2;
        }
    }
}
    

    
    return 0;
}
