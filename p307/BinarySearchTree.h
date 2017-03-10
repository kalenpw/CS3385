// You should start by copying your BinaryTree project into here
// and modifying as necessary. Your BinarySearch tree will look
// something like
//
//    template <typename T, typename GetKey>
//    class BinarySearchTree {
//    };
//
// One of the data members will be
//
//    GetKey _getKey;

#pragma once

// Provides I/O
#include <iostream>
#include <string>

#include "./util.h"


//BNode Class 
template <typename T>
class BNode {
    public:
        //Constructor
        BNode(const T& data){
            _data = data;
            _left = NULL;
            _right = NULL;
            _parent = NULL;
        }

        //Methods
        //Returns data contained in node
        const T& data() const {
            return _data;
        }
        //Returns next node
        const BNode* left() const{
            return _left;
        }

        //Returns previous node
        const BNode* right() const{
            return _right;
        }

        //Returns the parent node
        const BNode* parent() const {
            return _parent;
        }

        //Returns next node
        BNode* left(){
            return _left;
        }

        //Returns previous node
        BNode* right(){
            return _right;
        }

        //Returns previous node
        BNode* parent(){
            return _parent;
        }
        //Sets next node
        void setLeft(BNode<T>* node){
            _left = node;
        }
        //Sets previous node
        void setRight(BNode<T>* node){
            _right = node;
        }

        //Sets the parent node
        void setParent(BNode<T>* node){
            _parent = node;
        }
        
    private:
        T _data;
        BNode* _left;
        BNode* _right;
        BNode* _parent;

};


//    template <typename T, typename GetKey>
//    class BinarySearchTree {
//    };
//
// One of the data members will be
//
//    GetKey _getKey;
//BinaryTree class
template <typename T, typename GetKey>
class BinarySearchTree {
    public:
        //Constructor
        BinarySearchTree(){
            _head = NULL;
        }

        //Methods
       

        void setHead(BNode<T>* value){
            _head = value;
        }
        BNode<T>* head(){
            return _head;
        }

        T min(){
            BNode<T>* node = _head;
            while(node->left() != NULL){
                node = node->left();
            }   
            return node->data();
        }

        T max(){
            BNode<T>* node = _head;
            while(node->right() != NULL){
                node = node->right();
            }   
            return node->data();
        }

        //Inserts an element into BinarySearchTree
        void insert(T toInsert){
            BNode<T>* z = new BNode<T>(toInsert);//node
            BNode<T>* y = NULL;//cNode
            BNode<T>* x = _head;//fNode

            while(x != NULL){
                y = x;
                if(getKey(z->data()) < getKey(y->data())){
                    x = y->left();
                    //x->setLeft(x);
                }
                else{
                    x = y->right();
                    //x->setRight(x);
                }

            }
            
            z->setParent(y);
            if(y == NULL){
                _head = z;
            }
            else if(getKey(z->data()) < getKey(y->data())){
                y->setLeft(z);
            }
            else{
                y->setRight(z);
            }

        }        

        T get(int key){ 
            if(dynamic_cast<BNode*<Student>>(_head)){
                return new Student("Kalen", 1, 2);
            }
            return getImpl(key, _head); 
        }

        T getImpl(int key, BNode<T>* node){

            if(dynamic_cast<BNode*<Student>>(node)){
                return new Student("Kalen", 1, 2);
            }
            if(node != NULL){
                if(key == getKey(node->data())){
                    return node->data();
                }
                if(key < getKey(node->data())){
                    return getImpl(key, node->left());
                }
                if(key > getKey(node->data())){
                    return getImpl(key, node->right());
                }


            }
            else{
                return NULL;
            }
        }
        
        bool contains(int key){
            //return false;
            T find = getImpl(key, _head);
            
            if(find == NULL){
                return false;
            }
            else{
                return true;
            }
        } 

        void remove(int i){
            return;
        }
        void getInOrder(T key){
            return;
        }

        
        std::string toDotValues(BNode<T>* node) {
             using namespace std;
             string str;
             if(node == NULL){
                return "";
             }
             str += toDotValues(node->left());
             str += dotNode(node->data());
             str += toDotValues(node->right());
            
             return str;
             
         }
        //To dot methods
        std::string toDotImpl(BNode<T>* node) {
             using namespace std;
             if (!node) return "";
             
             string str;
             if (node->left()) {
                 str += dotEdge(node->data(), node->left()->data());
             }
             if (node->right()) {
                 str += dotEdge(node->data(), node->right()->data());
             }
  
             if (node->left()) {
                 str += toDotImpl(node->left());
             }
             if (node->right()) {
                 str += toDotImpl(node->right());
             }
             return str;
             
         }

         std::string toDot() {
           using namespace std;
           string str = "digraph G {\n";
           str += "graph [ordering=\"out\"]\n";
           str += toDotValues(_head);
           str += toDotImpl(_head);
           str += "}\n";
           return str;
         }

    private:
        BNode<T>* _head;
        GetKey getKey;

};

// TODO: add these functions to your BinaryTree class.
