#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

ll modpow(ll x,int n){
  if(n==0)return 1;
  if(n%2)return (modpow(x,n-1)*x)%MOD;
  else{
    ll halfpow=modpow(x,n/2)%MOD;
    return (halfpow*halfpow)%MOD;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,X,D;
  cin>>N>>X>>D;
  //Aiは長さN,初項X,公差Dの等差数列
  //Ai=D*i+X(0<=i<N)

  /*U=S+T S-T=S-(U-S)=2*S-U*/
  if(D==0){
    cout<<N+1<<endl;
    return 0;
  }
  else{
    D=abs(D);
    //S=k*X+I*D I=sum(i)
    //0+1+..+(k-1)<=I<=(N-k)+(N-k+1)+..+(N-1)
    //%Dしても重ならない
    ll ans=0;
  }
  return 0;
}
