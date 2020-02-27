#include <vector>
#include <cstdint>

using namespace std;

template<uint_fast64_t m>
struct Mcomb{
  using i64=uint_fast64_t;
  vector<i64>f;  //階乗
  vector<i64>finv; //階乗の逆元
  vector<i64>inv;  //逆元

  Mcomb(i64 max){
    f.resize(max+1,0);
    finv.resize(max+1,0);
    inv.resize(max+1,0);
    f[0]=f[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<=max;i++){
      f[i]=(f[i-1]*i%m)%m;
      inv[i]=m-inv[m%i]*(m/i)%m;
      finv[i]=finv[i-1]*inv[i]%m;
    }
  }

  //nCr=n!/r!(n-r)!
  i64 slove(i64 n,i64 r){
    if(n<r)return 0;
    if(n<0||r<0)return 0;
    return f[n]*(finv[r]*finv[n-r]%m)%m;
  }
};
