#include <vector>

using namespace std;

struct LazySegT{
  int sz;
  vector<int>v;
  vector<int>lazy;
  LazySegT(vector<int>x){
    int n=x.size();
    sz=1;while(sz<n)sz*=2;
    v.resize(2*sz-1,0);
    lazy.resize(2*sz-1,0);
    for(int i=0;i<n;i++)v[sz-1+i]=x[i];
    for(int i=sz-2;i>=0;i--)v[i]=v[2*i+1]+v[2*i+2];
  }
  void eval(int k,int l,int r){
    if(lazy[k]!=0){
      v[k]+=lazy[k];
      if(r-l>1){
        lazy[2*k+1]+=lazy[k]/2;
        lazy[2*k+2]+=lazy[k]/2;
      }
      lazy[k]=0;
    }
  }
  void add(int a,int b,int x){
    add_(a,b,x,0,0,sz);
  }
  void add_(int a,int b,int x,int k,int l,int r){
    eval(k,l,r);
    if(b<=l||r<=a)return;
    if(a<=l&&r<=b){
      lazy[k]+=x*(r-l);
      eval(k,l,r);
    }
    else{
      add_(a,b,x,2*k+1,l,(l+r)/2);
      add_(a,b,x,2*k+2,(l+r)/2,r);
      v[k]=v[2*k+1]+v[2*k+2];
    }
  }
  int getsum(int a,int b){
    return getsum_(a,b,0,0,sz);
  }
  int getsum_(int a,int b,int k,int l,int r){
    eval(k,l,r);
    if(b<=l||r<=a)return 0;
    if(a<=l&&r<=b)return v[k];
    int vl=getsum_(a,b,2*k+1,l,(l+r)/2);
    int vr=getsum_(a,b,2*k+2,(l+r)/2,r);
    return vl+vr;
  }
};
