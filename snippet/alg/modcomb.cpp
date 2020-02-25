#include <vector>
#include <cstdint>

using namespace std;

template<uint_fast64_t mod>
struct Modcomb{
  using i64=uint_fast64_t;
  vector<i64>fac; 
  vector<i64>finv; 
  vector<i64>inv;

  Modcomb(i64 max){
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
  }

  //nCr=n!/r!(n-r)!
  i64 slove(i64 n,i64 r){
    if(n<r)return 0;
    if(n<0||r<0)return 0;
    return fac[n]*(finv[r]*finv[n-r]%mod)%mod;
  }
};
