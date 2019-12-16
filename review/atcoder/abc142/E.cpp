//DP
//反省点 dpの遷移が下手くそ
//
//dp[i][j]->dp[i+1][j]の遷移を忘れていた

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

  int N,M;
  cin>>N>>M;
  vector<int>a(M),b(M);
  vector<vector<bool>>c(M,vector<bool>(N,false));
  for(int i=0;i<M;i++){
    cin>>a[i]>>b[i];
    for(int j=0;j<b[i];j++){
      int C;cin>>C;C--;
      c[i][C]=true;
    }
  }

  vector<vector<ll>>dp(M+1,vector<ll>(pow(2,N),INF/2));
  dp[0][0]=0;
  //10^3
  for(int i=0;i<M;i++){ 
    //4*10^3
    for(int j=0;j<pow(2,N);j++){ 
      dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
      int now=j;
      //12
      for(int k=0;k<N;k++){
        if(c[i][k]&&!((now>>k)&1))now+=pow(2,k);
      }
      dp[i+1][now]=min(dp[i+1][now],dp[i][j]+a[i]);
    }
  }
  ll ans=INF/2;
  for(int i=0;i<=M;i++){
    ans=min(ans,dp[i][pow(2,N)-1]);
  }
  if(ans==INF/2)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}
