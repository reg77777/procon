#include <iostream>


int main(){

  //2^10 mod 1000000007
  std::cout<<[](auto n,auto x,auto mod)->decltype(n){
    [=](auto f){
      return [=](auto... args){
        return f(f,args...);
      };
    }([=](auto f,auto n,auto x)->decltype(n){
        if(x==0)return 1;
        if(x%2)return ((n%mod)*(f(f,n,x-1)%mod))%mod;
        else {
          auto half=f(f,n,x/2)%mod;
          return half*half;
        }
    })(n,x);
  }(2,10,1000000007);

  return 0;
}
