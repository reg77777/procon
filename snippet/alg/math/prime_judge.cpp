#include <cstdint>

//素数判定
bool isprime(int_fast64_t x){
  for(int i=0;i*i<=x;i++){
    if(x%i==0)return false;
  }
  return true;
}
