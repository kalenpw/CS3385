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
        BinarySearchTree(T type, GetKey g){

        }

        //Methods
        void setHead(BNode<T>* value){
            _head = value;
        }
        BNode<T>* head(){
            return _head;
        }
        
        BNode<T>* find(const T& key, BNode<T>* node){
            return node; 
//            if(node != NULL){
//                if(key == node->data()){
//                    return node;
//                }
//                if(key < node->data()){
//                    return find(key, node->left());
//                }
//                else{
//                    return find(key, node->right());
//                }
//
//            }
//            else{
//                return NULL;
//            }
//            return NULL;
//            while(node != NULL){
//                if(node->data() == key){
//                    return node;
//                }
//
//                if(key > node->data()){
//                    node = node->right();
//                }
//                if(key < node->data()){
//                    node = node->left();
//                }
//                
//            }


//            if(node->data() == key){
//                return node;
//            }
//            else{
//                find(key, node->left());
//                find(key, node ->right());
//            }

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
           str += toDotImpl(_head);
           str += "}\n";
           return str;
         }

    private:
        BNode<T>* _head;
        GetKey _getKey;

};

// TODO: add these functions to your BinaryTree class.
