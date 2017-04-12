#pragma once

#include <cstddef>
#include <string>
#include <iostream>

// Your Node and DisjointSet classes will have references to each other.
// Circular references are handled by
//   1) making sure each least one of the references is a pointer.
//   2) declaring one of the classes before it is defined.
// For example,
//
//   // declaration of DisjointSet
//   class DisjointSet;
//
//   class Node {
//     // reference to DisjointSet
//   };
//
//   // definition of DisjointSet
//   class DisjointSet {
//   };

//place data structure code here
class DisjointSet;

class Node {
    public:
        //Constructor
        //No arg
        Node(){
        }
        //With given data
        Node(int data){
            _data = data;
        }

        //Accessors & mutators
        void setDisjointSet(DisjointSet* set){
            _set = set;
        }
        DisjointSet* getDisjointSet(){
            if(_set){
                std::cout << "Oops";
                return _set;
            }
            else{
                DisjointSet* set;
                //set->setSize(0);
                return set;
            }
        }
        void setData(int data){
            _data = data;
        }
        //getData()
        int data(){
            return _data;
        }

        void setNextNode(Node* node){
            _nextNode = node;
        }

        Node* getNextNode(){
            return _nextNode;
        }


    private:
        DisjointSet* _set;
        Node* _nextNode;
        int _data;
};

class DisjointSet{
    public:
        //constructor
        DisjointSet(){
            _size = 0;
        }
        
        //Accessor & mutator
        void setHead(Node* node){
            _head = node;
        }

        void setTail(Node* node){
            _tail = node;
        }
        
        void setSize(int amount){
            _size = amount;
        }
        int getSize(){
            return _size;
        }

        void increaseSizeBy(int amount){
            _size = _size + amount;
        }

    private:
        Node* _tail;
        Node* _head;
        int _size;
};

// TODO: uncomment function declarations and implement them in
// DisjointSet.cpp

Node* makeSet();

// // A node can hold data.
Node* makeSet(int data);

Node* find(Node* x);

void link(Node* x, Node* y);
// // If x is greater than or equal to y, then merge y into x.
// // Otherwise, merge x into y. After merging, be sure to delete
// // one of the disjoint sets or you will have memory leaks.
// // For example, if merging y into x, then after merging
// // you would do something like
// //     delete y->set();
// // You do not need to delete any nodes, since they are
// // simply transferred from one set to another.
// //
// // This function is called makeUnion() rather than just
// // union() because union is a reserved word in C++.
void makeUnion(Node* x, Node* y);

// // This function converts the input image to grayscale and quantizes the
// // intensities into numBins unique intensities. In effect, it reduces
// // the number of colors in the image. This function is a warm-up
// // to learn the Bitmap interface so you can use it for finding
// // connected components in the connectedComponents() function.
 void quantizeImage(
     const std::string& infile, const std::string& outfile, int numBins);

// // This function finds all connected components in the quantized input
// // image and writes a new image with each connected component having
// // its own color.
 void connectedComponents(
     const std::string& infile, const std::string& outfile, int numBins);
