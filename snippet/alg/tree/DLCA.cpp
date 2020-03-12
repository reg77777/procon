#include <vector>
#include <cstdint>

using namespace std;

struct Doubling{
  vector<vector<int>>table;
  int log;
  int sz;
  //sz:要素数 lim:最大の数
  Doubling(int sz,int64_t lim):sz(sz),log(64-__builtin_clzll(lim)){
    table.resize(sz,vector<int>(log,-1));
  }
  void set_next(int now,int next){
    table[now][0]=next;
  }
  void build(){
    for(int j=0;j<log-1;j++){
      for(int i=0;i<sz;i++){
        if(table[i][j]==-1)table[i][j+1]=-1;
        else table[i][j+1]=table[table[i][j]][j]; //iの2^j先の2^j先->iの2^(j+1)先
      }
    }
  }
};

struct DLCA{
  int r;
  vector<int>par;
  vector<int>dep;
  vector<vector<int>>g;
  Doubling*d;
  DLCA(vector<vector<int>>g,int r):g(g),r(r){
    int N=g.size();
    par.resize(N,0);
    dep.resize(N,0);
    d=new Doubling(N,N);
    dfs(r,-1,0);
    for(int i=0;i<N;i++)d->set_next(i,par[i]);
    d->build();
  }
  void dfs(int x,int p,int val){
    par[x]=p;
    dep[x]=val;
    for(auto it:g[x]){
      if(it!=p)dfs(it,x,val+1);
    }
  }
  int query(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=d->log-1;i>=0;i--){
      if(((dep[x]-dep[y])>>i)&1)x=d->table[x][i];
    }
    if(x==y)return x;
    for(int i=d->log-1;i>=0;i--){
      if(d->table[x][i]!=d->table[y][i]){
        x=d->table[x][i];
        y=d->table[y][i];
      }
    }
    return d->table[x][0];
  }
};
