#include <cstdint>

using namespace std;

template<int m>
int modpow(int x,int n){
  if(n==0)return 1;
  if(n%2)return ((x%m)*(modpow<m>(x,n-1)%m))%m;
  else {
    int half=modpow<m>(x,n/2)%m;
    return (half*half)%m;
  }
}
