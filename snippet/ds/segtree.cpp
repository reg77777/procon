#include <vector>
#include <cstdint>
#include <functional>

using namespace std;

struct SegTree{
  vector<int>v;
  int sz;
  SegTree(int n){
    sz=1;while(sz<n)sz*=2;
    v.resize(2*sz-1,0);
  }
  SegTree(vector<int>a){
    sz=1;while(sz<a.size())sz*=2;
    v.resize(2*sz-1,0);
    for(int i=0;i<a.size();i++)v[i+sz-1]=a[i];
    for(int i=sz-2;i>=0;i--)v[i]=v[2*i+1]+v[2*i+2];
  }
  void add(int x,int val){
    x+=sz-1;
    v[x]=v[x]+val;
    while(x>0){
      x=(x-1)/2;
      v[x]=v[2*x+1]+v[2*x+2];
    }
  }
  void update(int x,int val){
    x+=sz-1;
    v[x]=val;
    while(x>0){
      x=(x-1)/2;
      v[x]=v[2*x+1]+v[2*x+2];
    }
  }
  int sum(int a,int b,int l=0,int r=-1,int k=0){
    if(r==-1)r=sz;
    if(a<=l&&r<=b)return v[k];
    if(b<=l||r<=a)return 0;
    int lval=sum(a,b,l,(l+r)/2,2*k+1);
    int rval=sum(a,b,(l+r)/2,r,2*k+2);
    return lval+rval;
  }
};
