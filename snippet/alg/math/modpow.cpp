#include <cstdint>

using namespace std;

template<uint_fast64_t m>
int_fast64_t mpow(int_fast64_t x,int_fast64_t n){
  using i64=int_fast64_t;
  if(n==0)return 1;
  if(n%2)return ((x%m)*(mpow<m>(x,n-1)%m))%m;
  else {
    i64 half=mpow<m>(x,n/2)%m;
    return (half*half)%m;
  }
}
