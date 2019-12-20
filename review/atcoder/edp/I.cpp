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

  int N;
  cin>>N;
  vector<double>p(N);
  for(int i=0;i<N;i++)cin>>p[i];
  vector<vector<double>>dp(N+1,vector<double>(N+1,0));
  dp[0][0]=1;
  for(int i=1;i<=N;i++){
    for(int j=0;j<=N;j++){
      if(j-1>=0)dp[i][j]+=dp[i-1][j-1]*p[i-1];
      dp[i][j]+=dp[i-1][j]*(1-p[i-1]);
    }
  }
  double ans=0;
  for(int i=0;i<=N;i++){
    if(i>N/2)ans+=dp[N][i];
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;
}
