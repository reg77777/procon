#include <cstdint>

//$BAG?tH=Dj(B
bool isprime(int_fast64_t x){
  if(x==1)return false;
  for(int i=2;i*i<=x;i++){
    if(x%i==0)return false;
  }
  return true;
}
