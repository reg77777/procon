#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct UnionFind{

  vector<int>par;
  vector<int>rank;

  UnionFind(int size){
    rank.resize(size,1);
    par.resize(size);
    for(int i=0;i<size;i++)par[i]=i;
  }

  void unite(int node1,int node2){
    if(is_connected(node1,node2))return;
    node1=find(node1);
    node2=find(node2);
    if(rank[node1]>rank[node2])swap(node1,node2);
    par[node1]=node2,rank[node2]+=rank[node1];
  }
  int find(int node){
    if(par[node]==node)return node;
    return par[node]=find(par[node]);
  }
  bool is_connected(int node1,int node2){
    return find(node1)==find(node2);
  }
  int size(int node){
    return rank[find(node)];
  }

};
