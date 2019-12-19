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

  ll N,W;
  cin>>N>>W;
  vector<ll>w(N),v(N);
  for(int i=0;i<N;i++)cin>>w[i]>>v[i];
  vector<vector<ll>>dp(N+1,vector<ll>(W+1,0));
  for(int i=1;i<=N;i++){
    for(int j=0;j<=W;j++){
      if(j-w[i-1]>=0)dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
      else dp[i][j]=dp[i-1][j];
    }
  }
  ll ans=0;
  for(int i=0;i<=W;i++){
    ans=max(ans,dp[N][i]);
  }
  cout<<ans<<endl;
  return 0;
}
