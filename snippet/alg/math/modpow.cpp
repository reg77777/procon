#include <cstdint>

using namespace std; //ごめんなさい

template<uint_fast64_t m>
int_fast64_t mpow(int_fast64_t x,int_fast64_t n){
  using i64=int_fast64_t;
  if(x==0)return 1;
  if(x%2)return ((n%m)*(mpow<m>(n,x-1)%m))%m;
  else {
    i64 half=mpow<m>(n,x/2)%m;
    return (half*half)%m;
  }
}
