#include "./MergeSort.h"
#include <iostream>

using namespace std;

void merge(int* array, int p, int q, int r){
    int lengthOne = q - p + 1;
    int lengthTwo = r - q;
    
    int* left = new int[lengthOne + 1];
    int* right = new int[lengthTwo + 1];

    for(int i = 0; i < lengthOne; i++){
        left[i] = array[p + i];
    }
    for(int j = 0; j < lengthTwo; j++){
        right[j] = array[q + j + 1];
    }

    left[lengthOne + 1] = 100;
    right[lengthTwo + 1] = 100;

    int ii = 0;
    int jj = 0;

    for(int k = p; k < r; k++){
        cout << "k = " << k << std::endl;
        if(left[ii] <= right[jj]){
            array[k] = left[ii];
            ii = ii + 1;
        }
        else if(array[k] = right[jj]){
            jj = jj + 1;
        }
    }

    //cout << "FUCK";
}

void mergeSortImpl(int* array, int p, int r){
    int q;
    if(p < r){
        q = (p + r) / 2;
        mergeSortImpl(array, p, q);
        mergeSortImpl(array, q+1, r);
        merge(array, p, q, r);
    }
    //cout << "Merge sort impl";
}

void mergeSort(int* array, int length){
    //cout << "Hello world";
}
