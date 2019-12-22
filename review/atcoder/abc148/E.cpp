//算数
//
//反省点:イメージをしていなかった
//死んだほうがマシ
#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  cin>>N;
  if(N%2==0){
    ll ans=0;
    for(ll i=5;i<=N;i*=5){
      ans+=N/i/2;
    }
    cout<<ans<<endl;
  }
  else{
    cout<<0<<endl;
  }
  return 0;
}
