// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2025/2026 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/
// -------------------------------------------------------------
// Binary Tree
// Last update: 08/11/2025
// -------------------------------------------------------------

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <stack>

template <class T> class BTree {
private:
  struct Node {
    T value;            // The value stored on the node
    Node *left, *right; // Pointers to left and right child
  };

  // The tree 
  Node *root;           // Pointer to the root node
  
public:

  // Constructor: initially the tree is empty
  BTree() {
    root = nullptr;
  }

  // Destructor: delete all nodes (garbage collection) [see slide 33]
  ~BTree() {
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
  // Count the number of nodes (see slides 11 and 12)
  // ---------------------------------------------------------
  
  int numberNodes() {
    return numberNodes(root);
  }   
  
  int numberNodes(Node *n) {
    if (n == nullptr) return 0;
    return 1 + numberNodes(n->left) + numberNodes(n->right);
  }

  // ---------------------------------------------------------
  // Height of the tree (see slides 13 and 14)
  // ---------------------------------------------------------

  int height() {
    return height(root);
  }
  
  int height(Node *n) {
    if (n == nullptr) return -1;
    return 1 + std::max(height(n->left), height(n->right));
  }

  // ---------------------------------------------------------
  // Does the tree contain value 'val'? (see slides 15 and 16)
  // ---------------------------------------------------------
  
  bool contains(const T & val) {
    return contains(root, val);
  }

  bool contains(Node *n, const T & val) {
    if (n == nullptr) return false;
    if (n->value == val) return true;
    return contains(n->left, val) || contains(n->right, val);
  }  

  // ---------------------------------------------------------
  // Print tree in PreOrder (see slides 18 and 19)
  // ---------------------------------------------------------

  void printPreOrder() {
    std::cout << "PreOrder:";
    printPreOrder(root);
    std::cout << std::endl;
  }

  void printPreOrder(Node *n) {
    if (n == nullptr) return;
    std::cout << " " << n->value;
    printPreOrder(n->left);
    printPreOrder(n->right);
  }

  // ---------------------------------------------------------
  // Print tree in InOrder (see slides 20 and 21)
  // ---------------------------------------------------------
  
  void printInOrder() {
    std::cout << "InOrder:";
    printInOrder(root);
    std::cout << std::endl;
  }

  void printInOrder(Node *n) {
    if (n == nullptr) return;
    printInOrder(n->left);
    std::cout << " " << n->value;
    printInOrder(n->right);
  }

  // ---------------------------------------------------------
  // Print tree in PostOrder (see slides 20 and 22)
  // ---------------------------------------------------------
  
  void printPostOrder() {
    std::cout << "PostOrder:";
    printPostOrder(root);
    std::cout << std::endl;
  }

  void printPostOrder(Node *n) {
    if (n == nullptr) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    std::cout << " " << n->value;
  } 

  // ---------------------------------------------------------
  // Print tree in Breadt-First order using a queue
  // (see slides 23, 24 and 25)
  // ---------------------------------------------------------

  void printBFS() {
    std::cout << "BFS:";

    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *cur = q.front();
      q.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        q.push(cur->left);
        q.push(cur->right);
      }
    }
    
    std::cout << std::endl;
  }

  // ---------------------------------------------------------
  // Print tree in Depth-First order using a stack
  // (see slides 26 and 27)
  // ---------------------------------------------------------
  
  void printDFS() {
    std::cout << "DFS:";

    std::stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
      Node *cur = s.top();
      s.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        s.push(cur->left);
        s.push(cur->right);
      }
    }
    
    std::cout << std::endl;
  }

  // ---------------------------------------------------------
  // Read a tree in PreOrder from standard input
  // (see slides 28, 29 and 30)
  // ---------------------------------------------------------

  void read(std::string null) {
    root = readNode(null);
  }
  
  Node *readNode(std::string null) {
    std::string buffer;
    std::cin >> buffer;
    if (buffer == null) return nullptr;
    Node *n = new Node;
    std::istringstream ss(buffer);
    ss >> n->value;
    n->left = readNode(null);
    n->right = readNode(null);    
    return n;
  }

  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------

  int numberLeafs(Node* n){
    if(n==nullptr){return 0;}
    if(n->right==nullptr && n->left==nullptr){return 1;}
    return numberLeafs(n->right)+numberLeafs(n->left);
  }

  int numberLeafs(){
    return numberLeafs(root);
  }

  bool strict(Node* n){
    if(n->right==nullptr & n->left==nullptr){
      return true;
    }
    if(n->right!=nullptr & n->left==nullptr){
      return false;
    }
    if(n->right==nullptr & n->left!=nullptr){
      return false;
    }
    return strict(n->right) && strict(n->left);
  }

  bool strict(){
    return strict(root);
  }

  T & path(std::string s, Node* n){
    std::string s1;
    for(int i=1;i<s.size();i++){
      s1+=s[i];
    }
    if(s[0]=='R'){return path(s1,n->right);}
    if(s[0]=='L'){return path(s1,n->left);}
    return n->value;
  }


  T & path(std::string s){
    if(s=="_"){return root->value;}
    return path(s,root);
  }

  void nodesLevel(int k, int l, Node* n, std::vector<int>& v){
    if(n==nullptr){return;}
    if(k==l){v[k]++;return;}
    v[l]++;
    l++;
    nodesLevel(k,l,n->right,v);
    nodesLevel(k,l,n->left,v);
  }

  int nodesLevel(int k){
    std::vector<int> v(k+1,0);
    nodesLevel(k,0,root,v);
    return v[k];
  }

  int countEven(Node* n){
    if(n==nullptr){return 0;}
    if(n->value%2==0){return 1+countEven(n->right)+countEven(n->left);}
    return countEven(n->right)+countEven(n->left);
  }

  int countEven(){
    return countEven(root);
  }

  void sumLevels(std::vector<int>& v, int l, Node* n){
    if(n==nullptr){return;}
    v[l]+=n->value;
    l++;
    sumLevels(v,l,n->right);
    sumLevels(v,l,n->left);
    return;
  }

  std::vector<int> sumLevels(){
    std::vector<int> v(height()+1,0);
    sumLevels(v,0,root);
    return v;
  }

  std::pair<std::string, int> maxSum(std::string& s, Node* n){

    auto l= maxSum(s,n->left);
    auto r=maxSum(s,n->right);
  }

  std::string maxSum(){
    std::string s;

    return s;
  }
};


#endif