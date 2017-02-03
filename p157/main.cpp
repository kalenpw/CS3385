//------------------------------------------------------------
//
// CS 3385
// Project p157
//
// In this project you will be implementing a heap.
//
// The at() function is included to give you an idea of the
// syntax for adding your functions to the class.
//
// Files to submit:
//   * Heap.h
//   * Heap.cpp
// 
//------------------------------------------------------------

#include <iostream>

#include "./Heap.h"

using namespace std;

#define TEST(test) { \
  testNum++; \
  if (!(test)) { \
    cerr << "Test " << testNum << " failed" << endl; \
    numFails++; \
  } \
}

int runTests() {
  int numFails = 0;
  int testNum = 0;

  // {
  //   int A[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  //   Heap h(A, 8, 8);
  //   TEST(h == A);
  //   TEST(h.at(0) == 1);
  //   TEST(h.at(1) == 2);
  //   TEST(h.at(4) == 5);
  //   TEST(h.left(0) == 1);
  //   TEST(h.right(0) == 2);
  //   TEST(h.parent(1) == 0);
  //   TEST(h.parent(2) == 0);
  //   TEST(h.left(1) == 3);
  //   TEST(h.right(1) == 4);
  //   TEST(h.parent(3) == 1);
  //   TEST(h.parent(4) == 1);
  //   TEST(h.left(2) == 5);
  //   TEST(h.right(2) == 6);
  //   TEST(h.parent(5) == 2);
  //   TEST(h.parent(6) == 2);
  // }

  // {
  //   int A[] = { 1, 2, 3 };
  //   Heap h(A, 3, 3);
  //   h.maxHeapify(0);
  //   int target[] = { 3, 2, 1 };
  //   TEST(h == target);
  //   h.maxHeapify(0);
  //   TEST(h == target);
  //   h.maxHeapify(1);
  //   TEST(h == target);
  //   h.maxHeapify(2);
  //   TEST(h == target);
  // }

  // {
  //   int A[] = { 1, 2, 3, 4 };
  //   // Note that we're passing in a larger array than the size
  //   // of the heap.
  //   Heap h(A, 4, 3);
  //   h.maxHeapify(1);
  //   int target[] = { 1, 2, 3 };
  //   TEST(h == target);
  // }

  // {
  //   int A[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
  //   Heap h(A, 10, 10);
  //   h.maxHeapify(1);
  //   int target[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
  //   TEST(h == target);
  // }

  // {
  //   // In your buildMaxHeap() function, you should not set the
  //   // heap size to the size of the array -- it is set in the
  //   // constructor. Also, remember that the algorithm in the
  //   // book uses 1-based indices, so your bounds will look
  //   // different.
  //   int A[] = { 1 };
  //   Heap h(A, 1, 1);
  //   h.buildMaxHeap();
  //   int target[] = { 1 };
  //   TEST(h == target);
  // }

  // {
  //   int A[] = { 1, 2, 3 };
  //   Heap h(A, 3, 3);
  //   h.buildMaxHeap();
  //   int target[] = { 3, 2, 1 };
  //   TEST(h == target);
  // }

  // {
  //   int A[] = { 1, 2, 3, 4 };
  //   Heap h(A, 4, 4);
  //   h.buildMaxHeap();
  //   int target[] = { 4, 2, 3, 1 };
  //   TEST(h == target);
  // }

  // {
  //   int A[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  //   Heap h(A, 10, 10);
  //   h.buildMaxHeap();
  //   int target[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
  //   TEST(h == target);
  // }

  const int numSuccesses = testNum - numFails;
  cout << numSuccesses << "/" << testNum << " tests succeeded" << endl;

  return numFails;
}

int main() {
  return runTests();
}
