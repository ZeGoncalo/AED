// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2025/2026 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/
// -------------------------------------------------------------
// Singly Linked List
// Last update: 20/10/2024
// -------------------------------------------------------------

#ifndef SLLIST_H
#define SLLIST_H

#include <iostream>
#include <sstream>
#include <cassert>
#include <string>


// -------------------------------------------------------------
// Simple Node<T> class with a link to the next node
// -------------------------------------------------------------

template <class T>
class Node {

private:
  T value;   // value in the node
  Node<T> *next;  // pointer to next node

public:
  Node(const T & v, Node<T> *n): value(v), next(n) {}

  T & getValue() {
    return value;
  }

  Node<T> *getNext() {
    return next;
  }

  void setValue(T & v) {
    value=v;
  }

  void setNext(Node<T> *n) {
    next = n;
  }
};


// -------------------------------------------------------------
// Implementation of a SinglyLinkedList<T>
// -------------------------------------------------------------

template <class T>
class SinglyLinkedList {

private:
  Node<T> *first;    // first element
  int length;         // length

public:

  // Construtor (creates empty list)
  SinglyLinkedList(): first(nullptr), length(0) {}

  // Destrutor
  ~SinglyLinkedList() {
    while(!isEmpty()) {
      assert(first != nullptr && "length bigger than what it should be");
      removeFirst();
    }
    assert(first == nullptr && "length smaller than what it should be");
  }

  // Returns the length of the list
  int size() {
    return length;
  }

  // Returns true iff the list is empty
  bool isEmpty() {
    return (length == 0);
  }

  // Adds v to the head of the list
  void addFirst(const T & v) {
    Node<T> *newNode = new Node<T>(v, first);
    first = newNode;
    length++;
  }

  // Adds v to the end of the list
  void addLast(const T & v) {
    Node<T> *newNode = new Node<T>(v, nullptr);
    if (isEmpty()) {
      first = newNode;
    } else {
      Node<T> *cur = first;
      while (cur->getNext() != nullptr)
        cur = cur->getNext();
      cur->setNext(newNode);
    }
    length++;
  }

  // Returns the reference to the first value
  T & getFirst() {
    assert(!isEmpty() && "trying to get first from empty list");
    return first->getValue();
  }

  // Returns the last value
  T & getLast() {
    assert(!isEmpty() && "trying to get last from empty list");
    Node<T> *cur = first;
    while (cur->getNext() != nullptr)
      cur = cur->getNext();
    return cur->getValue();
  }

  // Removes the first element (does nothing if the list is empty)
  void removeFirst() {
    if (isEmpty()) return;
    Node<T> *victim = first;
    first = first->getNext();
    delete victim;
    length--;
  }

  // Removes the last element (does nothing if the list is empty)
  void removeLast() {
    if (isEmpty()) return;
    if (length == 1) {
      delete first;
      first = nullptr;
    } else {
      // Using length and a for loop to show an alternative to while loop
      Node<T> *cur = first;
      for (int i=0; i<length-2; i++)
        cur = cur->getNext();
      Node<T> *victim = cur->getNext();
      cur->setNext(victim->getNext());
      delete victim;
    }
    length--;
  }

  // Convert a list to a string
  std::string toString() {
    if (isEmpty()) return "{}";
    std::stringstream sstr;
    sstr <<  "{" <<  first->getValue();
    Node<T> *cur = first->getNext();
    while (cur != nullptr) {
      sstr << "," << cur->getValue();
      cur = cur->getNext();
    }
    sstr <<  "}";
    std::string str;
    std::getline(sstr,str);
    return str;
  }


  T & get(int pos){
    Node<T> *a;
    a=first;
    int i=0;
    while(i<pos){
      a=a->getNext();
      i++;
    }
    return a->getValue();
  }

  int count(T & v){
    Node<T> *cur=first;
    int res=0;
    while(cur!=nullptr){
      if(cur->getValue()==v){
        res++;
      }
      cur=cur->getNext();
    }
    return res;
  }

  void remove(int pos){
    if (isEmpty()) return;
    if(pos<0 || pos>=length){return;}
    if(pos==0){removeFirst();return;}
    if(pos==length-1){removeLast();return;}
    int i=0;
    Node<T> *cur=first,*victim;
    while(i<pos-1){cur=cur->getNext();i++;}
    victim=cur->getNext();
    cur->setNext(victim->getNext());
    delete victim;
    length--;
  }

  void insert(int pos, const T & v){
    if(pos<0 || pos>length){return;}
    if(pos==0){addFirst(v);return;}
    if(pos==length){addLast(v);return;}
    int i=0;
    Node<T> *cur=first, *temp;
    while(i<pos-1){
      cur=cur->getNext();
      i++;
    }
    temp=cur->getNext();
    Node<T> *newNode = new Node<T>(v, temp);
    cur->setNext(newNode);
    length++;
  }

  void duplicate(){
    if (isEmpty()) return;
    int i=0;
    Node<T> *cur=first;
    while(i<length){
      Node<T> *newNode = new Node<T>(cur->getValue(), cur->getNext());
      cur->setNext(newNode);
      i++;
      cur=newNode->getNext();
    }
    length*=2;
  }

  void removeAll(const T & v) {
    if (isEmpty()) return;
    Node<T> *cur = first;
    Node<T> *anterior = nullptr;
    while (cur != nullptr){
      if (cur->getValue() == v){
        Node<T> *victim = cur;
        cur = cur->getNext();
        if (anterior == nullptr){first = cur;}
        else {anterior->setNext(cur);}
        delete victim;
        length--;
      }
      else {
        anterior = cur;
        cur = cur->getNext();
      }
    }
  }


};

#endif
