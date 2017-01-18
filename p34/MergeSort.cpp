#include "./MergeSort.h"
#include <iostream>

using namespace std;

//Kalen Williams
//18 January 2017
void merge(int* array, int p, int q, int r){
    int lengthOne = q - p + 1;
    int lengthTwo = r - q;
    
    int* left = new int[lengthOne + 1];
    int* right = new int[lengthTwo + 1];
    
    int i = 0;
    int j = 0;

    for(int i = 0; i < lengthOne; i++){
        left[i] = array[p + i];
    }
    for(int j = 0; j < lengthTwo; j++){
        right[j] = array[q + j + 1];
    }

    left[lengthOne] = 100;
    right[lengthTwo] = 100; 
    
    i = 0;
    j = 0;

    for(int k = p; k <= r; k++){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i = i + 1;
        }
        else{
            array[k] = right[j];
            j = j + 1;
        }

    }

}

//Kalen Williams
//18 January 2017
void mergeSortImpl(int* array, int p, int r){
    int q;
    if(p < r){
        q = (p + r) / 2;
        mergeSortImpl(array, p, q);
        mergeSortImpl(array, q+1, r);
        merge(array, p, q, r);
    }
}

//Kalen Williams
//18 January 2017
void mergeSort(int* array, int length){
    int p;
    int r;

    p = 0;
    r = length - 1;

    mergeSortImpl(array, p, r);
}
