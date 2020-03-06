#include <vector>
#include <cstdint>
#include <map>

using namespace std; //$B$4$a$s$J$5$$(B

//$BAG0x?tJ,2r(B
map<int_fast64_t,int>prime_factor(int_fast64_t x){
  map<int_fast64_t,int>res;
  for(int_fast64_t i=2;i*i<=x;i++){
    while(x%i==0){
      res[i]++;
      x/=i;
    }
  }
  if(x!=1)res[x]=1;
  return res;
}

