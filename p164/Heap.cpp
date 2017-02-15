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
    std::cout << "The parent of " << i << " is " << parentIndex << std::endl;
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

void Heap::insert(Patient value){
    n++;
    int i = n - 1;
    A[i] = value;

    while(i >= 0 ){
        if(i == 0 && parent(i) == 0){
            //Don't do anything if on parent
            i = -1;
        }
        
        else{
            //Swap i with parent i if parent i is smaller
            int iPriority = A[i].priority();
            int iParentPriority = A[parent(i)].priority();

            if(iParentPriority < iPriority){
                swap(i, parent(i));

                i = parent(i);
            }
        }

    }
    

}


Patient Heap::extractMax(){
    Patient patientSwap = A[0];
    A[0] = A[n-1];
    A[n-1] = patientSwap;
}

//Get the max element of a max heap
Patient Heap::max(){
    return A[0];
}

//Turns a normal array into a max heap
void Heap::maxHeapify(int i){
    int leftIndex = left(i);
    int rightIndex = right(i);
    int largest = 0;
   
    int iPriority = A[i].priority(); 
    int leftPriority = A[leftIndex].priority();
    int rightPriority = A[rightIndex].priority();
    int largestPriority = 0;
    
    if(leftIndex <= n && leftPriority > iPriority){
        largest = leftIndex;
        largestPriority = A[leftIndex].priority();
    }
    else{
        largest = i;
        largestPriority = A[i].priority();
    }

    if(rightIndex <= n && rightPriority > largestPriority){
        largest = rightIndex;
        largestPriority = A[largest].priority();
    }

    if(largest !=  i){
        swap(largest, i);
        maxHeapify(largest); 
    }
   
}

void Heap::buildMaxHeap(){
    for(int i = n; i >= 0; i--){
        maxHeapify(i);
    }
}

void Heap::heapsort(){
    buildMaxHeap();
    for(int i = arraySize -1; i >= 1; i--){
        swap(0, i);
        n = n - 1;
        maxHeapify(0);
    }
}

void Heap::swap(int a, int b){
    Patient swap = A[a];
    A[a] = A[b];
    A[b] = swap;
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
