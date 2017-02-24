#pragma once

// Provides I/O
#include <iostream>
#include <sstream>
#include <string>

//------------------------------------------------------------
// ListNode class
// ListNodes are singly-linked.
//------------------------------------------------------------
template <typename T>
class ListNode {
 public:
  ListNode(const T& data) {
    _data = data;
    _next = NULL;
  }

  ListNode(const T& data, ListNode* next) {
    _data = data;
    _next = next;
  }

  const T& data() const { return _data; }
  const ListNode* next() const { return _next; }
  ListNode* next() { return _next; }
  void setNext(ListNode* next) { _next = next; }

 private:
  T _data;
  ListNode* _next;
};

//------------------------------------------------------------
// LinkedList class
//------------------------------------------------------------
template <typename T>
class LinkedList {
 public:
  LinkedList() {
    _head = NULL;
  }

  // Inserts a node to head of linked list
  void insert(ListNode<T>* node) {
    if(_head == NULL){
      node->setNext(NULL);
    } 
    else{
      node->setNext(_head);
    }
    _head = node;
  }
    
    //Returns the node with passed in value key
    ListNode<T>* find(const T& key) {
        ListNode<T>* currentNode = _head;
        while(currentNode != NULL && currentNode->data() != key){
            currentNode = currentNode->next();  
        }
        return currentNode; 
    }

    //Returns the node before the key
    ListNode<T>* findPreviousNode(const T& key){
        ListNode<T>* previousNode;
        ListNode<T>* currentNode = _head;
    
        while(currentNode != NULL && currentNode->data() != key){
            previousNode = currentNode;
            currentNode = currentNode->next();  
        }
        return previousNode;
    }

    // Removes and deletes the first node in the linked list that has data
    // equal to the  key
    void remove(const T& key) {
        return;
//        ListNode<T>* previousNode = findPreviousNode(key);
//        ListNode<T>* deleteNode;
//        ListNode<T>* nextNode;
//        if(previousNode->next() == NULL){
//                        
//        }
//
//        ListNode<T>* nodeToDelete = find(key);
//        ListNode<T>* previousNode = findPreviousNode(key);
//        ListNode<T>* nextNode;
//        if(nodeToDelete == NULL){
//           nextNode = NULL;
//           previousNode->setNext(NULL);
//        }
//        else{
//            nextNode = nodeToDelete->next();
//            previousNode->setNext(nextNode);
//        }
////        ListNode<T>* nextNode = nodeToDelete->next();
//        delete nodeToDelete;
                
    }

  friend std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
    ListNode<T>* node = list._head;
    while (node != NULL) {
      out << node->data();
      if (node->next() != NULL) {
        out << " -> ";
      }
      node = node->next();
    }
    return out;
  }

  std::string toString() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
  }

 private:
  ListNode<T>* _head;
};
