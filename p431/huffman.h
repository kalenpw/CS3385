#pragma once

#include <iostream>
#include <string>
#include <queue>

#include "./bit_buffer.h"

using std::string;
using std::vector;
using std::priority_queue;

//------------------------------------------------------------
// BNode class
//------------------------------------------------------------
template <typename T>
class BNode {
 public:
  BNode(const int key, const T& data) {
    _key = key;
    _data = data;
    _parent = _left = _right = NULL;
  }

  const int key() const { return _key; }
  const T& data() const { return _data; }

  const BNode* parent() const { return _parent; }
  BNode* parent() { return _parent; }
  void setParent(BNode* parent) { _parent = parent; }

  const BNode* left() const { return _left; }
  BNode* left() { return _left; }
  void setLeft(BNode* left) { _left = left; }

  const BNode* right() const { return _right; }
  BNode* right() { return _right; }
  void setRight(BNode* right) { _right = right; }

 private:
  int _key;
  T _data;
  BNode* _parent;
  BNode* _left;
  BNode* _right;
};

// Put your BNode class from your BinarySearchTree project above
// this, then comment-out the following line. You can then refer
// to BNode<char> as simply Node.
typedef BNode<char> Node;

// This class will allow us to use the stl priority_queue.
class NodeComp {
 public:
  bool operator()(Node* a, Node* b) {
    return a->key() > b->key();
  }
};

// struct CharFreq {
//   char c;
//   int f;
//   CharFreq() {}
//   CharFreq(char c_, int f_) : c(c_), f(f_) {}
// };

// Returns the root of the tree
// Node* buildBinaryTree(const vector<CharFreq>& chars);

// Returns the root of the tree built using algorithm 431
// of the book. Remember to NOT include characters that
// have frequency of zero.
Node* buildBinaryTree(const int* freq);

void getCodewords(Node* root, string codewords[]);

char getChar(Node* root, bit_buffer& buf);

// Count the frequencies of each character. So
// freq['a'] gives the number of occurrences of
// 'a' in the data string.
//
// To iterate over a string:
//    for (int i = 0; i < data.size(); ++i) {
//      cout << data[i];
//    }
void countFrequencies(const string& data, int* freq);

// This function is provided for you.
string getHeader(int* freq);

// To compress the given data you will need to do
// a number of things, including building the
// frequency table, building the binary tree,
// getting the codewords, writing a header (see
// below) and writing the data itself. You should
// write auxiliary functions and test them as you
// go.
//
// A getHeader() function is provided to you to
// get the header in proper format. It will look
// something like the following. The first number
// is the number of characters with non-zero
// frequency.
// 6
// a 45
// b 13
// c 12
// d 16
// e 9
// f 5
//
// After writing the header you will write the data
// itself in compressed format.
string compressData(const string& data);

// This function reads frequencies from the header,
// builds the binary tree and uses the tree itself
// (not the codewords) to uncompress the data.
string uncompressData(const string& data);

