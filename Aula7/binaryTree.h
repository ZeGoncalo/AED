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

  int numberLeafs() {
    return numberLeafs(root);
  }

  int numberLeafs(Node* n) {
    if (n == nullptr) return 0;
    if (n->left == nullptr && n->right == nullptr) return 1;
    return numberLeafs(n->left) + numberLeafs(n->right);
  }

  int strict() {
    return strict(root);
  }

  int strict(Node* n) {
    if (n->left == nullptr && n->right == nullptr) return true;
    if (n->left != nullptr && n->right == nullptr) return false;
    if (n->left == nullptr && n->right != nullptr) return false;
    return strict(n->left) && strict(n->right);
  }

  T & path(std::string s){
    Node* cur=root;
    for(char c: s){
      if(c=='_'){
        return root->value;
      }
      if(c=='L'){
        cur=cur->left;
      }
      if(c=='R'){
        cur=cur->right;
      }
    }
    return cur->value;
  }

  int nodesLevel(int k){
    return nodesLevel(root, k);
  }

  int nodesLevel(Node* n, int k){
    if (n==nullptr) return 0;
    if (k==0) return 1;
    return nodesLevel(n->left, k-1) + nodesLevel(n->right, k-1);
  }

  int countEven() {
    return countEven(root);
  }

  int countEven(Node* n) {
    if (n == nullptr) return 0;
    int count = 0;
    if (n->value % 2 == 0) count = 1;
    return count + countEven(n->left) + countEven(n->right);
  }

  std::vector<int> sumLevels() {
    std::vector<int> sums;
    if (root == nullptr) return sums;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      int levelSize = q.size();
      int levelSum = 0;
      for (int i = 0; i < levelSize; i++) {
        auto node = q.front();
        q.pop();
        levelSum += node->value;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      sums.push_back(levelSum);
    }
    return sums;
  }

  std::string maxSum() {
    if (!root) return "";
    return maxSum(root).second;
  }

  std::pair<int, std::string> maxSum(Node* node) {
    if (!node->left && !node->right) {
      return {node->value, ""};
    }
    std::pair<int, std::string> leftSum = {0, ""};
    std::pair<int, std::string> rightSum = {0, ""};
    if (node->left)  leftSum  = maxSum(node->left);
    if (node->right) rightSum = maxSum(node->right);
    if (leftSum.first >= rightSum.first) {
      return {node->value + leftSum.first, "L" + leftSum.second};
    } else {
      return {node->value + rightSum.first, "R" + rightSum.second};
    }
  }
};


#endif
