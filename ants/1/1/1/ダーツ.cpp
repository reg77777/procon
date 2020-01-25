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

  //S<=M->M S>M->0
  ll N,M;
  cin>>N>>M;
  vector<ll>p(N);
  for(int i=0;i<N;i++)cin>>p[i];
  p.push_back(0);
  vector<ll>a;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N;j++){
      a.push_back(p[i]+p[j]);
    }
  }
  sort(rng(a));
  ll ans=0;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N;j++){
      ll A=M-p[i]-p[j];
      auto x=upper_bound(rng(a),A);
      if(x!=a.end()&&x!=a.begin())ans=max(ans,p[i]+p[j]+*(x-1));
    }
  }
  cout<<ans<<endl;
  return 0;
}
