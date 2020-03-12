#include <vector>

using namespace std;

//0-index
struct BIT{
  vector<int>node;
  int sz;
  BIT(int sz):sz(sz){
    node.resize(sz,0);
  }
  int sum(int i){
    int res=0;
    for(i--;i>=0;i=(i&(i+1))-1)res+=node[i];
    return res;
  }
  void add(int i,int x){
    for(;i<sz;i|=i+1)node[i]+=x;
  }
  int sum(int l,int r){
    return sum(r)-sum(l);
  }
};
