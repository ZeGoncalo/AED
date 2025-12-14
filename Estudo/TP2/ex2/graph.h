// -------------------------------------------------------------
// Algorithms and Data Structures 2025/2026 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/
// -------------------------------------------------------------
// A simple lightweight graph class
// Last update: 24/11/2024
// -------------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

class Graph {
  struct Edge {
    int dest;   // Destination node
    int weight; // An integer weight
  };

  struct Node {
    std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
    bool visited;        // Has the node been visited in a graph traversal?
    int color;
  };

  int n;                   // Graph size (vertices are numbered from 1 to n)
  bool hasDir;             // false: undirected; true: directed
  std::vector<Node> nodes; // The list of nodes being represented

public:
  // Constructor: nr nodes and direction (default: undirected)
  Graph(int num, bool dir = false) : n(num), hasDir(dir), nodes(num+1) {}

  // Add edge from source to destination with a certain weight
  void addEdge(int src, int dest, int weight = 1) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
  }

  // --------------------------------------------------------------

  // Read a graph in the format:
  // nr_nodes directed/undirected weighted/unweighted
  // nr_edges
  // src_1 dest_1 <weight_1>
  // src_2 dest_2 <weight_2>
  // ...
  // src_n dest_n <weight_n>
  static Graph *readGraph() {
    int n;
    std::string sdirection, sweight;
    std::cin >> n >> sdirection >> sweight;
    bool directed = (sdirection == "directed")?true:false;
    bool weighted = (sweight == "weighted")?true:false;

    Graph *g = new Graph(n, directed);
    int e;
    std::cin >> e;
    for (int i=0; i<e; i++) {
      int u, v, w = 1;
      std::cin >> u >> v;
      if (weighted) std::cin >> w;
      g->addEdge(u, v, w);
    }
    return g;
  }

  // --------------------------------------------------------------
  // Depth-First Search (DFS): example implementation
  // --------------------------------------------------------------
  void dfs(int v) {
    std::cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        dfs(w);
    }
  }

  // --------------------------------------------------------------
  // Breadth-First Search (BFS): example implementation
  // --------------------------------------------------------------
  void bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    std::queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
      int u = q.front(); q.pop();
      std::cout << u << " ";  // show node order
      for (auto e : nodes[u].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
          q.push(w);
          nodes[w].visited = true;
        }
      }
    }
  }


  // --------------------------------------------------------------

  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------

  void no_print_dfs(int v) {
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        no_print_dfs(w);
    }
  }

  int nrConnectedComponents(){
    int res=0;
    for(Node n:nodes){n.visited=false;}
    for (int i=1;i<=n;i++){
      if (nodes[i].visited==false){
        no_print_dfs(i);
        res++;
      }
    }
    return res;
  }

  int largestComponent(){
    int prev=0, max=0, cur=0;
    for(Node n:nodes){n.visited=false;}
    for (int i=1;i<=n;i++){
      if (nodes[i].visited==false){
        no_print_dfs(i);
        prev=cur;
        cur=0;
        for(Node n:nodes){
          if (n.visited==true){cur++;}
        }
        if (max<cur-prev){max=cur-prev;}
      }
    }
    return max;
  }

  void topo_dfs(int i, std::list<int>& v) {
    nodes[i].visited = true;
    for (auto e : nodes[i].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        topo_dfs(w,v);
    }
    v.push_front(i);
  }

  std::list<int> topologicalSorting(){
    std::list<int> v;
    for (int i=1;i<=n;i++){
      nodes[i].visited=false;
    }
    for (int i=1;i<=n;i++){
      if (nodes[i].visited==false){
        topo_dfs(i,v);
      }
    }
    return v;
  }

  bool cycle_dfs(int v) {
    nodes[v].color=1;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (nodes[w].color == 1)
        return true;
      if (nodes[w].color == 0 && cycle_dfs(w))
        return true;
    }
    nodes[v].color=2;
    return false;
  }


  bool hasCycle() {
    for (int i = 1; i <= n; i++){
      nodes[i].color=0;
    }
    for (int i = 1; i <= n; i++) {
      if (nodes[i].color == 0) {
        if (cycle_dfs(i))
          return true;
      }
    }
    return false;
  }

  bool bipartite_dfs(int v){
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (nodes[w].color == nodes[v].color){
        return false;
      }
      if (nodes[w].color==2){
        nodes[w].color=!nodes[v].color;
        if (!bipartite_dfs(w)){return false;};
      }
    }
    return true;
  }

  bool isBipartite(){
    for (int i = 1; i <= n; i++){
      nodes[i].color=2;
    }
    nodes[1].color=1;
    for (int i = 1; i <= n; i++) {
      if (nodes[i].color == 2 || i==1) {
        if (!bipartite_dfs(i))
          return false;
      }
    }
    return true;
  }
};

#endif