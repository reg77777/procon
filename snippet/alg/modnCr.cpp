//O(N)
#include <iostream>
#include <vector>

struct{
  int mod;
  std::vector<long long int>fac;
  std::vector<long long int>finv;
  std::vector<long long int>inv;
  void init(int max,int mod){
    this->mod=mod;
    fac.resize(max+1,0);
    finv.resize(max+1,0);
    inv.resize(max+1,0);
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<=max;i++){
      fac[i]=(fac[i-1]*i%mod)%mod;
      inv[i]=mod-inv[mod%i]*(mod/i)%mod;
      finv[i]=finv[i-1]*inv[i]%mod;
    }
    return;
  }
  long long int slove(int n,int r){
    if(n<r)return 0;
    if(n<0||r<0)return 0;
    return fac[n]*(finv[r]*finv[n-r]%mod)%mod;
  }
}modComb;

int main(){
  modComb.init(5100,1000000007);
  std::cout<<modComb.slove(5,2);
  return 0;
}
