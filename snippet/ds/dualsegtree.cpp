#include <vector>

using namespace std;

struct DualSegT{
  int sz;
  vector<int>v;
  DualSegT(int n){
    sz=1;while(sz<n)sz*=2;
    v.resize(2*sz-1,0);
  }
  void add(int a,int b,int x){
    add_(a,b,x,0,0,sz);
  }
  void add_(int a,int b,int x,int k,int l,int r){
    if(b<=l||r<=a)return;
    if(a<=l&&r<=b){
      v[k]+=x;
      return;
    }
    add_(a,b,x,2*k+1,l,(l+r)/2);
    add_(a,b,x,2*k+2,(l+r)/2,r);
  }
  int get(int x){
    x+=sz-1;
    int res=0;
    for(int i=x;i>0;i=(i-1)/2)res+=v[i];
    res+=v[0];
    return res;
  }
};

