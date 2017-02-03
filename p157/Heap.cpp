#include "./Heap.h"
#include <iostream>
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
Heap::Heap(int* inArray, int inArraySize, int inHeapSize) {
  // TODO: initialize your class data members. An array dynamically allocated
  // as follows:
  // A = new int[size];
  // If you allocate an array like this you MUST deallocate it in your
  // destructor. This is done for you in the destructor below.
}

// Destructor. Cleans up memory.
Heap::~Heap() {
  delete [] A;
}

// Note: the function name is prefixed by Heap:: (the class
// name followed by two colons). Any function defined in
// the .cpp file must have this prefix.
int Heap::at(int i) {
  return A[i];
}

bool Heap::operator==(const Heap& rhs) {
  if (n != rhs.n) return false;
  for (int i = 0; i < n; ++i) {
    if (A[i] != rhs.A[i]) return false;
  }
  return true;
}

bool Heap::operator==(const int* rhs) {
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
