// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2025/2026 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/
// -------------------------------------------------------------
// Binary Search Tree
// Last update: 16/11/2024
// -------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

template <class T> class BSTree {
private:
  struct Node {
    T value;            // The value stored on the node
    Node *left, *right; // Pointers to left and right child
  };
  
  Node *root;
  
public:

  // Constructor: initially the tree is empty
  BSTree() {
    root = nullptr;
  }

  // Destructor: delete all nodes (garbage collection)
  ~BSTree() {
    destroy(root);
  }

  // Recursively delete left and right subtrees and then current node
  void destroy(Node *n) {
    if (n == nullptr) return;
    destroy(n->left);
    destroy(n->right);
    delete n;
  }

  // ---------------------------------------------------------
  // Count the number of nodes
  // ---------------------------------------------------------
  
  int numberNodes() {
    return numberNodes(root);
  }   
  
  int numberNodes(Node *n) {
    if (n == nullptr) return 0;
    return 1 + numberNodes(n->left) + numberNodes(n->right);
  }

  // ---------------------------------------------------------
  // Height of the tree
  // ---------------------------------------------------------

  int height() {
    return height(root);
  }
  
  int height(Node *n) {
    if (n == nullptr) return -1;
    return 1 + std::max(height(n->left), height(n->right));
  }

  // ---------------------------------------------------------
  // Does the tree contain value 'val' ?
  // ---------------------------------------------------------

  bool contains(const T & val) {
    return contains(root, val);
  }

  bool contains(Node *n, const T & val) {
    if (n == nullptr) return false;
    if (val < n->value) return contains(n->left, val);
    if (val > n->value) return contains(n->right, val);
    return true;
  }

  // ---------------------------------------------------------
  // Insert value 'val' in the tree
  // ---------------------------------------------------------
  
  bool insert(const T & val) {
    if (contains(val)) return false;
    root = insert(root, val);
    return true;
  }

  Node *insert(Node *n, const T & val) {
    if (n == nullptr) {
      Node *aux = new Node;
      aux->value = val;
      aux->left = aux->right = nullptr;
      return aux;
    } else if (val < n->value) {
      n->left = insert(n->left, val);
    } else if (val > n->value) {
      n->right = insert(n->right, val);
    }
    return n;
  }

  // ---------------------------------------------------------
  // Remove value 'val' from the tree
  // ---------------------------------------------------------

  bool remove(const T & val) {
    if (!contains(val)) return false;
    root = remove(root, val);
    return true;
  }

  Node *remove(Node *n, const T & val) {
    if (val < n->value) n->left = remove(n->left, val);
    if (val > n->value) n->right = remove(n->right, val);
    else if (n->left == nullptr) {
      Node *tmp = n->right;
      delete n;
      return tmp;
    } else if (n->right == nullptr) {
      Node *tmp = n->left;
      delete n;
      return tmp;
    } else {
      Node *max = n->left;
      while (max->right != nullptr) max = max->right;
      n->value = max->value;
      n->left = remove(n->left, max->value);
    }
    return n;
  }
  
  // ---------------------------------------------------------
  // Print tree in preorder, incluing N for the null values
  // ---------------------------------------------------------  
  
  void printPreOrder() {
    std::cout << "preOrder:";
    printPreOrder(root);
    std::cout << std::endl;
  }

  void printPreOrder(Node *n) {
    if (n == nullptr)
      std::cout << " N";
    else {
      std::cout << " " << n->value;
      printPreOrder(n->left);
      printPreOrder(n->right);
    }
  }
  
  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------

  Node* findNode(Node* node, const T& val) const {
    while (node) {
      if (val == node->value) return node;
      if (val < node->value) node = node->left;
      else node = node->right;
    }
    return nullptr;
  }

  int balance(const T& val)  {
    Node* n = findNode(root, val);
    if (!n) return 0;
    int hl = height(n->left);
    int hr = height(n->right);
    return hr - hl;
  }

  std::pair<bool,int> isAVL(Node* n) {
    if (n==nullptr){return {true,0};}
    auto left=isAVL(n->left);
    auto right=isAVL(n->right);
    if (!left.first || !right.first){return {false,0};}
    int h= 1+ std::max(left.second,right.second);
    bool b= std::abs(left.second-right.second)<=1;
    return {b,h};
  }

  int isAVL() {
    return isAVL(root).first;
  }

  Node* findNodeParent(const T &x, Node* &parent) {
    parent = nullptr;
    Node* cur = root;
    while (cur) {
      if (cur->value == x) return cur;
      parent = cur;
      if (x < cur->value) cur = cur->left;
      else cur = cur->right;
    }
    return nullptr;
  }

  void rightRotate(const T & x){
    Node* parent = nullptr;
    Node* a = findNodeParent(x, parent);
    if (!a) return;
    if (!a->left) return;
    Node* b = a->left;
    a->left = b->right;
    b->right = a;
    if (parent == nullptr) {
      root = b;
    }
    else if (parent->left == a) {
      parent->left = b;
    }
    else {
      parent->right = b;
    }
  }
};



#endif