//Kalen Williams
//CS 3385
//08 Feb. 2017
//Heap.cpp

#include "./Heap.h"
#include <iostream>
#include <sstream>
// Provides floor, ceil, etc.
#include <cmath>

using namespace std;

Heap::Heap() {
  arraySize = 0;
  n = 0;
  A = NULL;
}

// This assumes that every element of the array is an
// element of the heap.
Heap::Heap(Patient* inArray, int inArraySize, int inHeapSize) {
  // TODO: initialize your class data members. An array dynamically allocated
  // as follows:
  // A = new int[size];
  // If you allocate an array like this you MUST deallocate it in your
  // destructor. This is done for you in the destructor below.

  arraySize = inArraySize;
  n = inHeapSize;
  A = new Patient[arraySize];
  for(int i = 0; i < inHeapSize; i++){
    A[i] = inArray[i];
  }
}

// Destructor. Cleans up memory.
Heap::~Heap() {
  delete [] A;
}

// Note: the function name is prefixed by Heap:: (the class
// name followed by two colons). Any function defined in
// the .cpp file must have this prefix.

Patient Heap::at(int i) const{
    return A[i];
}
int Heap::parent(int i) const{
    int parentIndex = (int) (i - 1) / 2;
    return parentIndex;
}

int Heap::left(int i) const {
    int leftIndex = (i + 1)* 2 - 1;
    return leftIndex;
}

int Heap::right(int i) const {
    int rightIndex =  (i + 1) * 2;
    return rightIndex;
}

bool Heap::hasLeft(int i) const {
//    int leftIndex = left(i);
//    leftIndex += 1;
//    if(leftIndex > n){
//        return false;
//    }
//    return true;
}

bool Heap::hasRight(int i) const{
//    int rightIndex = right(i);
//    rightIndex += 1;
//    if(rightIndex > n){
//        return false;
//    }
//    return true;
}

void Heap::maxHeapify(int i){
    int leftIndex = left(i);
    int rightIndex = right(i);
    int largest = 0;

    Patient leftPatient = A[leftIndex];
    Patient rightPatient = A[rightIndex];
    Patient largestPatient = A[largest];
    
    if(leftIndex <= n && A[leftIndex] > A[i]){
        largest = leftIndex;
    }
    else{
        largest = i;
    }

    if(rightIndex <= n && A[rightIndex] > A[largest]){
        largest = rightIndex;
    }

    if(largest !=  i){
        int swap;
        swap = A[largest];
        A[largest] = A[i];
        A[i] = swap;
        maxHeapify(largest); 
    }
   
}

void Heap::buildMaxHeap(){
//    for(int i = n; i >= 0; i--){
//        maxHeapify(i);
//    }
}



bool Heap::operator==(const Heap& rhs) {
  if (n != rhs.n) return false;
  for (int i = 0; i < n; ++i) {
    if (A[i] != rhs.A[i]) return false;
  }
  return true;
}

bool Heap::operator==(const Patient* rhs) {
  for (int i = 0; i < n; ++i) {
    if (A[i] != rhs[i]) return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream& out, const Heap& h) {
  out << "[";
  for (int i = 0; i < h.n; ++i) {
    out << h.A[i];
    if (i < h.n-1) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}

string toDotImpl(const Heap& h, int i) {
  using namespace std;
  stringstream ss;
  if (h.hasLeft(i)) {
    ss << toDotImpl(h, h.left(i));
    ss << "\"" << h.at(i) << "\" -> \""
       << h.at(h.left(i)) << "\"\n";
  }
  if (h.hasRight(i)) {
    ss << toDotImpl(h, h.right(i));
    ss << "\"" << h.at(i) << "\" -> \""
       << h.at(h.right(i)) << "\"\n";
  }
  return ss.str();
}

string toDot(const Heap& h) {
  using namespace std;
  stringstream ss;
  ss << "digraph G {\n";
  ss << "graph [ordering=\"out\"]\n";
  ss << "\"" << h.at(0) << "\"\n";
  ss << toDotImpl(h, 0);
  ss << "}\n";
  return ss.str();
}
