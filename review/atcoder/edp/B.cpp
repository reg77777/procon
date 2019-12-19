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

  int N,K;
  cin>>N>>K;
  vector<ll>h(N);
  for(int i=0;i<N;i++)cin>>h[i];
  vector<ll>dp(N,INF);
  dp[0]=0;
  for(int i=1;i<N;i++){
    for(int j=1;j<=K;j++){
      if(i-j>=0)dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
    }
  }
  cout<<dp[N-1]<<endl;
  return 0;
}
