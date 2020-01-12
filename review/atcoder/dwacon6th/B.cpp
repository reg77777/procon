//数え上げ
//
//反省点 期待値で考えられなかった,部分和はO(N)
#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

template<std::uint_fast64_t Mod>
struct modint{
  using u64=int_fast64_t;
  u64 a;
  constexpr modint(const u64 x=0) noexcept:a(x%Mod){}
  constexpr u64 &value() noexcept{return a;}
  constexpr const u64 &value() const noexcept{return a;}
  constexpr modint operator+(const modint rhs)const noexcept{
    return modint(*this)+=rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept{
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept{
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept{
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept{
    a+=rhs.a;
    if(a>=Mod)a-=Mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept{
    if(a<rhs.a)a+=Mod;
    a-=rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept{
    a=a*rhs.a%Mod;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept{
    u64 exp=Mod-2;
    while(exp){
      if(exp%2)*this*=rhs;
      rhs*=rhs;
      exp/=2;
    }
    return *this;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<ll>x(N);
  for(int i=0;i<N;i++)cin>>x[i];
  vector<modint<MOD>>f(N);
  f[0]=f[1]=1;
  for(int i=2;i<N;i++)f[i]=f[i-1]*(i%MOD);
  vector<modint<MOD>>C(N,1);
  for(int i=1;i<N;i++)C[i]=C[i-1]+modint<MOD>(1)/modint<MOD>(i+1);
  modint<MOD>ans=0;
  for(int i=0;i<N-1;i++)ans+=modint<MOD>(x[i+1]-x[i])*C[i];
  ans*=f[N-1];
  cout<<ans.a<<endl;

  return 0;
}
