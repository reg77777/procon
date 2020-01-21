#include <cstdint>

#define MOD 1000000007
long long int modpow(long long int x,long long int n){
  if(x==0)return 1;
  if(x%2)return ((n%MOD)*(modpow(n,x-1)%MOD))%MOD;
  else {
    long long int half=modpow(n,x/2)%MOD;
    return (half*half)%MOD;
  }
}
