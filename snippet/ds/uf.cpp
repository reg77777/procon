#include <vector>
#include <bits/stdc++.h>

using namespace std; //ごめんなさい

//Union Find
struct UF{
  vector<int>p; //p[i]=ノードiの親
  vector<int>r; //rank[i]=ノードiのランク
  UF(int sz){
    r.resize(sz,0);
    p.resize(sz);
    for(int i=0;i<sz;i++)p[i]=i;
  }
  void u(int x,int y){ //1
    x=root(x);
    y=root(y);
    if(r[x]==r[y])r[x]++;
    if(r[x]>r[y])p[y]=x,r[x]+=r[y];
    else p[x]=y,r[y]+=r[x];
  }
  int root(int x){
    if(p[x]==x)return x;
    return root(x=p[x]);
  }
  bool isu(int x,int y){ //2
    return root(x)==root(y);
  }
  int size(int x){
    return r[root(x)];
  }
};
