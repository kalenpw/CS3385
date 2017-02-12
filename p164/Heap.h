// Provides I/O
#include <iostream>
// Provides size_t
#include <cstdlib>
// Provides INT_MAX and INT_MIN
// You can consider INT_MIN to be negative infinity
// and INT_MAX to be infinity
#include <climits>

#include "Patient.h"

//------------------------------------------------------------
// Heap class
//------------------------------------------------------------
class Heap {
 public:
  // Constructor
  Heap();

  // This constructor assumes that every element of the array is an
  // element of the heap.
  Heap(Patient* inArray, int inArraySize, int inHeapSize);

  // Destructor
  ~Heap();

  // Accesses an element of the array.
  Patient at(int i) const;  
  // Gets parent index of element at i
  int parent(int i) const;

  // Return element to the  left of i
  int left(int i) const;

  // Return element to the right of i
  int right(int i) const;

  // Checks if an element has a left child
  bool hasLeft(int i) const;

  // Checks if an elemnt has a right child
  bool hasRight(int i) const;

  // "Max heapifies" an array
  void maxHeapify(int i);

  // builds a max heap
  void buildMaxHeap();
  

  // Allows comparison between results
  bool operator==(const Heap& rhs);
  bool operator==(const Patient* rhs);

  // Useful for debugging. To use:
  //   Heap h;
  //   cout << h << endl;
  friend std::ostream& operator<<(std::ostream& out, const Heap& h);
  
 private:
  // The array
  Patient* A;

  // Size of the array
  int arraySize;

  // The number of elements in the heap
  int n;
};

// Useful for debugging. To use:
//   Heap h;
//   cout << h << endl;
std::string toDot(const Heap& h);
