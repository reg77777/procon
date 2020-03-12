#include <iostream>

using namespace std;

template<uint_fast64_t mod>
struct modint{
  using i64=int_fast64_t;
  i64 a;
  constexpr modint(const i64 x=0) noexcept:a(x%mod){}

  constexpr modint operator+(const modint obj)const noexcept{return modint(*this)+=obj;}
  constexpr modint operator-(const modint obj)const noexcept{return modint(*this)-=obj;}
  constexpr modint operator*(const modint obj)const noexcept{return modint(*this)*=obj;}
  constexpr modint operator/(const modint obj)const noexcept{return modint(*this)/=obj;}

  constexpr modint&operator+=(const modint obj)noexcept{
    a+=obj.a;
    if(a>=mod)a-=mod;
    return *this;
  }
  constexpr modint&operator++(const modint obj)noexcept{
    a++;
    if(a>=mod)a-=mod;
    return *this;
  } 
  constexpr modint&operator-=(const modint obj)noexcept{
    if(a<obj.a)a+=mod;
    a-=obj.a;
    return *this;
  }
  constexpr modint&operator--(const modint obj)noexcept{
    if(a<1)a+=mod;
    a--;
    return *this;
  } 
  constexpr modint&operator*=(const modint obj)noexcept{
    a=a*obj.a%mod;
    return *this;
  }
  constexpr modint&operator/=(modint obj)noexcept{
    //a^(-1)=a^(mod-2)
    i64 exp=mod-2;
    while(exp){
      if(exp%2)*this*=obj;
      obj*=obj;
      exp/=2;
    }
    return *this;
  }

  friend ostream&operator<<(ostream&os,const modint&obj)noexcept{
    return os<<obj.a;
  }
  friend istream&operator<<(istream&is,const modint&obj)noexcept{
    i64 i;
    obj=modint<mod>(i);
    return(is);
  }
};
