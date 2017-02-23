#pragma once

template <typename T>
void insertionSort(T* A, const int n){
    int i = 1;
    int j = 0;

    for(i; i < n; i++){
        j = i;

        while(j > 0 && A[j] < A[j-1]){
            T swap = A[j];
            A[j] = A[j-1];
            A[j-1] = swap;
            j = j - 1;
        }
    }
}

