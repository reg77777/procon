#include<iostream>

int main(){

  std::cout<<[](auto f){
    return [=](auto... args){
      return f(f,args...);
    };
  }([](auto f,auto a,auto b)->decltype(a){
      if(a==0)return b;
      else return f(f,b%a,a);
  })(3,6);

  return 0;
}
