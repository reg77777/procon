#include <iostream>

long long int modpow(long long int x,int n){
  if(n==0)return 1;
  if(n%2==0){
    long long int half=modpow(x,n/2);
    return half*half;
  }
  else return modpow(x,n-1)*x;
}

int main(){
  std::cout<<modpow(2,10);
  return 0;
}
