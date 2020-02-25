#include <cstdint>

using namespace std; //ごめんなさい

int_fast64_t gcd(int_fast64_t a,int_fast64_t b){
  if(b==0)return a;
  return gcd(b,a%b);
}
