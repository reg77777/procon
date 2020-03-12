#include <vector>
#include <cstdint>

using namespace std;

struct Sum{
  vector<int_fast64_t>node;
  template<typename T>
  Sum(vector<T>v){
    node.resize(v.size(),0);
    for(int i=0;i<v.size();i++)node[i+1]=node[i]+v[i];
  }
  int_fast64_t sum(int x){
    return node[x];
  }
  int_fast64_t sum(int l,int r){
    return node[r]-node[l];
  }
};
