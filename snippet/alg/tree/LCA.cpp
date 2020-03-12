#include <vector>

using namespace std;

struct LCA{
  int r; 
  vector<int>par;
  vector<int>d;
  vector<vector<int>>g;
  LCA(vector<vector<int>>g,int r):g(g),r(r){
    int N=g.size();
    par.resize(N,0);
    d.resize(N,0);
    dfs(r,-1,0);
  }
  void dfs(int x,int p,int val){
    par[x]=p;
    d[x]=val;
    for(auto it:g[x]){
      if(it!=p)dfs(it,x,val+1);
    }
  }
  int query(int x,int y){
    while(d[x]>d[y])x=par[x];
    while(d[x]<d[y])y=par[y];
    while(x!=y)x=par[x],y=par[y];
    return x;
  }
};
