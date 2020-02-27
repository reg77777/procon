#include <vector>
#include <cstdint>
#include <functional>

using namespace std; //‚²‚ß‚ñ‚È‚³‚¢

template<typename T=int_fast64_t>
struct segT{
  vector<T>v;
  using F=function<T(T,T)>;
  F f;
  T e;
  int sz;
  segT(int n){
    f=[](T a,T b){return a+b;};
    e=0;
    sz=1;while(sz<n)sz*=2;
    v.resize(2*sz-1,e);
  }
  segT(int n,T e,F f):e(e),f(f){
    sz=1;while(sz<n)sz*=2;
    v.resize(2*sz-1,e);
  }
  void add(int x,T val){
    x+=sz-1;
    v[x]=f(v[x],val);
    while(x>0){
      x=(x-1)/2;
      v[x]=f(v[2*x+1],v[2*x+2]);
    }
  }
  void update(int x,T val){
    x+=sz-1;
    v[x]=val;
    while(x>0){
      x=(x-1)/2;
      v[x]=f(v[2*x+1],v[2*x+2]);
    }
  }
  T sum(int a,int b,int l=0,int r=-1,int k=0){
    if(r==-1)r=sz;
    if(a<=l&&r<=b)return v[k];
    if(b<=l||r<=a)return e;
    T lval=sum(a,b,l,(l+r)/2,2*k+1);
    T rval=sum(a,b,(l+r)/2,r,2*k+2);
    return f(lval,rval);
  }
};
