#include <cstdint>
#include <iostream>

using namespace std; //$B$4$a$s$J$5$$(B

int_fast64_t gcd(int_fast64_t a,int_fast64_t b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int_fast64_t lcm(int_fast64_t a,int_fast64_t b){
  return a*b/gcd(a,b);
}
