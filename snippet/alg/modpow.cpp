#include <cstdint>

using namespace std; //ごめんなさい

template<uint_fast64_t mod>
int_fast64_t modpow(int_fast64_t x,int_fast64_t n){
  using i64=int_fast64_t;
  if(x==0)return 1;
  if(x%2)return ((n%mod)*(modpow<mod>(n,x-1)%mod))%mod;
  else {
    i64 half=modpow<mod>(n,x/2)%mod;
    return (half*half)%mod;
  }
}
