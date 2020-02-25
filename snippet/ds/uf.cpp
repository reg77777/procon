#include <vector>

using namespace std; //ごめんなさい

struct UF{
  vector<int>par;
  vector<int>rank;
  UF(int sz){
    rank.resize(sz,0);
    par.resize(sz);
    for(int i=0;i<sz;i++)par[i]=i;
  }
  void u(int x,int y){
    x=root(x);
    y=root(y);
    if(rank[x]==rank[y])rank[x]++;
    if(rank[x]>rank[y])par[y]=x;
    else par[x]=y;
  }
  int root(int x){
    if(par[x]==x)return x;
    return root(x=par[x]);
  }
  bool isu(int x,int y){
    return root(x)==root(y);
  }
};
