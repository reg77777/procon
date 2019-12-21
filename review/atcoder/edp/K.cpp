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
  vector<int>a(N);
  for(int i=0;i<N;i++)cin>>a[i];
  vector<bool>dp(K+1);
  dp[0]=false;
  for(int i=1;i<=K;i++){
    bool no=true;
    bool ok=false;
    for(int j=0;j<N;j++){
      if(i-a[j]>=0){
        no=false;
        if(!dp[i-a[j]])ok=true;
      }
    }
    if(no)dp[i]=false;
    else if(ok)dp[i]=true;
  }
  if(dp[K])cout<<"First"<<endl;
  else cout<<"Second"<<endl;
  return 0;
}
