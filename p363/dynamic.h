#pragma once
#include <climits>
#include <iostream>
// Here is the signature for cutRodNaive. The int& means that the
// parameter is being called by reference. So to increment
// callcount you will do the following:
//      callcount++;
//int cutRodNaive(const int* p, int n, int& callcount) {

// Here is the signature for cutRodMemoImpl, which is the 
// implementation function for cut rod using memoization.
// Recall that arrays can be passed as a pointer to an int.
// int cutRodMemoImpl(const int* p, int n, int* memos, int& callcount) {

// Here is the signature for cutRodMemo.
// int cutRodMemo(const int* p, int n, int& callcount) {

void fillArrayWithValue(int* array, int size, int value){
    for(int i = 0; i <= size; i++){
        array[i] = value;
    }
}

void printArray(int* array, int size){
    for(int i = 0; i < size; i++){
        std::cout << array[i] << std::endl;
    }
}

int fibNaive(int fibIndex, int& callcount){
    callcount++;
    if(fibIndex == 0 || fibIndex == 1){
        return 1;
    }
    return fibNaive(fibIndex - 1, callcount) + fibNaive(fibIndex - 2, callcount);    
}

int getMax(int first, int second){
    if(first == second){
        return first;
    }
    else{
        return first > second ? first : second;
    }
}

int cutRodNaive(const int* p, int n, int& callcount){
    callcount++;
    if(n == 0){
        return 0;
    }
    int q = INT_MIN;
    
    for(int i = 1; i <= n; i++){
        q = getMax(q, p[i] + cutRodNaive(p, n-i, callcount)); 
        
    }
    return q;
}

int cutRodMemoImpl(const int* p, int n, int* memos, int& callcount){
    int q;
    callcount++;
    if(memos[n] >= 0){
        return memos[n];
    }
    if(n == 0){
        q = 0;
    }
    else{
        q = -1;
        for(int i = 1; i <= n; i++){
            q = getMax(q, p[i] + cutRodMemoImpl(p, n-i, memos, callcount)); 
        }
    }
    memos[n] = q;
    return q;
    
}

int cutRodMemo(const int* p, int n, int& callcount){
    int* memos = new int[n+1];
    fillArrayWithValue(memos, n, -1);
    return cutRodMemoImpl(p, n, memos, callcount);
}

//Fib
int fibMemoImpl(int n, int* memos, int& callcount){
    callcount++;
    if(n <= 1){
        return 1;
    } 
    if(memos[n] == -1){
        memos[n] = fibMemoImpl(n-1, memos, callcount)+fibMemoImpl(n-2,memos,callcount);
    }
    return memos[n];
}

int fibMemo(int n, int& callcount){
    int* memos = new int[n+1];
    fillArrayWithValue(memos, n, -1);
    return fibMemoImpl(n, memos, callcount);
}

