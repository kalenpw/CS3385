/*
 * I ended up not being able to figure out how to use the DisjointSet class
 * As a result nearly everything failed 
 */

#include <vector>

#include "./DisjointSet.h"
#include "./bmp.h"

Node* makeSet() {
//    DisjointSet set = new DisjointSet();
//    DisjointSet set();
    Node* node = new Node();
    node->setNextNode(node);
//    set.setHead(node);
    return node; 
}

Node* makeSet(int data) {
//    DisjointSet set = new DisjointSet();
    DisjointSet set();
    Node* node = new Node(data);
    return node;
}

Node* find(Node* x) {
    //Uncomment when all hope is lost to avoid seg fault
    Node* node = new Node(1);
    return node;

    if(x != x->getNextNode()){
        x->setNextNode(find(x->getNextNode()));
    } 
    return x->getNextNode();
    
    Node* parent = x->getNextNode();

    if(parent == x){
        return x;
    }
    else{
        return find(x->getNextNode());
    }
    
}

// If the size of x's set is greater than or equal to the
// size of y's set, then merge y into x. Otherwise, merge x
// into y. This is the weighted union described in the
// video and book.
//
// After merging, be sure to delete one of the disjoint
// sets or you will have memory leaks. For example, if
// merging y into x, then after merging you would do
// something like
//     delete y->set();
// You do not need to delete any nodes, since they are
// simply transferred from one set to another.
//
// This function is called makeUnion() rather than just
// union() because union is a reserved word in C++.
//
void link(Node* x, Node* y){
//    return;
    //if x.size > y.size:
    if(x->getDisjointSet()->getSize() > y->getDisjointSet()->getSize()){
        y->setNextNode(x); 
    }
    else{
        x->setNextNode(y);
        if(x->getDisjointSet()->getSize() == y->getDisjointSet()->getSize()){
            y->getDisjointSet()->increaseSizeBy(1);
        }
    }
    
    
}

void makeUnion(Node* x, Node* y) {
    link(find(x), find(y));
}

 void quantizeImage(
     const std::string& infile, const std::string& outfile, int numBins) {
   // Read the image
//   Bitmap b;
//   b.read(infile);
//
//   // TODO: iterate through each pixel of the image. You can get the
//   // dimensions of the image using b.width() and b.height(). You can
//   // get a quantized version of a pixel using b.quantized(x,y,numBins).
//   // You can write a new value to the pixel using b.setColor(x, y, c)
//   // where c is an integer intensity.
//
//   // Write the image
//   b.write(outfile);
 }

 void connectedComponents(
     const std::string& infile, const std::string& outfile, int numBins) {
   // Read the file
//   Bitmap b;
//   b.read(infile);
//   // Create a 2D array of nodes. The node pointers are not initialized.
//   std::vector<std::vector<Node*>> nodes(
//       b.width(), std::vector<Node*>(b.height()));
//
//   // TODO: initialize the node pointers, one for each pixel.
//
//   // TODO: Follow the algorithm you wrote in the homework to find
//   // connected components. You will use b.quantized(x, y, numBins)
//   // to get the pixel intensity.
//
//   // TODO: Overwrite the image giving each connected component a unique
//   // color. Each connected component should have a unique ID in the
//   // representative node's data(). Use this integer ID to get a unique
//   // color using the following code:
//   //    Color c = Color::createRandom(id);
//   // You can then set the pixel's color in the image using
//   //    b.setColor(x, y, c);
//
//   // Write the image
//   b.write(outfile);
 }


