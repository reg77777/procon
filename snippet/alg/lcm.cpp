#include <iostream>

int main(){
  std::cout<<[](auto a,auto b)->decltype(a){
    auto gcd=[=](auto f){
      return [=](auto... args){
        return f(f,args...);
      };
    }([](auto f,auto a,auto b)->decltype(a){
        if(a==0)return b;
        else return f(f,b%a,a);
        })(a,b);
    return a*b/gcd;
  }(5,4);
  return 0;
}
