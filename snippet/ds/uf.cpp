#include <vector>

using namespace std; //ごめんなさい

//Union Find
//
//0~N-1で添字付けられたノードに対して以下のクエリを実行する
//1. xとyを同じグループにする
//2. xとyが同じグループに属しているか返す
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
    if(r[x]>r[y])p[y]=x;
    else p[x]=y;
  }
  int root(int x){
    if(p[x]==x)return x;
    return root(x=p[x]);
  }
  bool isu(int x,int y){ //2
    return root(x)==root(y);
  }
};
