#pragma once

// Provides I/O
#include <iostream>

template <typename T>
void swap(T a, T b){
    T swap = a;
    a = b;
    b = swap;
}

template <typename T>
int partition(T* array, int p, int r){
    T x = array[p];
    int i = p;
    int j;

    for(j = p + 1; j < r; j++){
        if(array[j] <= x){
            i = i + 1;
            swap(array[i], array[j]);
        }
    }
    swap(array[i], array[p]);
    return i;
}

template <typename T>
void quicksortImpl(T* array, int p, int r){
    if(p < r){
        int q = partition(array, p, r);
        quicksortImpl(array, p, q);
        quicksortImpl(array, q + 1, r);
    }
}

template <typename T>
void quicksort(T* array, int length){
    quicksortImpl(array, 0, length);
}

