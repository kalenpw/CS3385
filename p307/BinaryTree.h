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

        //Returns next node
        BNode* left(){
            return _left;
        }

        //Returns previous node
        BNode* right(){
            return _right;
        }
        //Sets next node
        void setLeft(BNode<T>* node){
            _left = node;
        }
        //Sets previous node
        void setRight(BNode<T>* node){
            _right = node;
        }
        
    private:
        T _data;
        BNode* _left;
        BNode* _right;

};


//BinaryTree class
template <typename T>
class BinaryTree {
    public:
        //Constructor
        BinaryTree(){

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

};

// TODO: add these functions to your BinaryTree class.
