#include "./InsertionSort.h"

//Insertion sort algorithm
//Kalen Williams 09 January 2017
void insertionSort(int* array, int length) {
  // TODO: Implement this function
  int i = 1;
  int swap = 0; 
  int j = 0;

  for(i; i < length; i++){
    j = i;
    
    while(j > 0 && array[j] < array[j-1]){
        swap = array[j];
        array[j] = array[j-1];
        array[j-1] = swap;
        j = j - 1;
    }  
  }
  
}
