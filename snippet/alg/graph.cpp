#include <iostream>
#include <vector>

template<typename T>
struct Edge{
  int to,from;
  T cost;
};

template<typename T>
struct Node{
  std::vector<Edge<T>>go;
  std::vector<Edge<T>>come;
  T cost;
};

template<typename T>
struct Graph{
  std::vector<Node<T>>nodes;
  std::vector<Edge<T>>edges;

  using node=Node<T>;
  using edge=Edge<T>;

  void add_node(int n){
    for(int i=0;i<n;i++)nodes.push_back(node());
  }

  void add_edge(int to,int from){
    edges.push_back(edge(to,from));
  }
};
