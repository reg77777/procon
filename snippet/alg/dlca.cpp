//https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.htmlを写しました

#include<vector>

using namespace std; //ごめんなさい

struct DLCA{
  int LOG;
  vector<int>dep;
  vector<vector<int>>g;
  vector<vector<int>>table;

  DLCA(vector<vector<int>>&g):g(g),dep(g.size()),LOG(32-__builtin_clz(g.size())){
    table.assign(LOG,vector<int>(g.size(),-1));
  }

  //全ての葉の親をtable[0]に記録
  void dfs(int idx,int par,int d){
    //idxの一つ上の親
    table[0][idx]=par;
    //根からの距離
    dep[idx]=d;
    for(auto to:g[idx]){
      if(to!=par)dfs(to,idx,d+1);
    }
  }

  void build(){
    dfs(0,-1,0);
    //LOG=floor(log(g.size()));
    //ダブリング
    for(int k=0;k+1<LOG;k++){
      for(int i=0;i<table[k].size();i++){
        if(table[k][i]==-1)table[k+1][i]=-1;
        else table[k+1][i]=table[k][table[k][i]];
      }
    }
  }

  int query(int u,int v){
    //深さを揃える
    if(dep[u]>dep[v])swap(u,v);
    for(int i=LOG-1;i>=0;i--){
      if(((dep[v]-dep[u])>>i)&1)v=table[i][v];
    }
    if(u==v)return u;
    //同じになるまでちょっとずつ近づく
    for(int i=LOG-1;i>=0;i--){
      if(table[i][u]!=table[i][v]){
        u=table[i][u];
        v=table[i][v];
      }
    }
    return table[0][u];
  }

};
