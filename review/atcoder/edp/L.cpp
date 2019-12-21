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
  vector<ll>a(N);
  for(int i=0;i<N;i++)cin>>a[i];
  vector<vector<ll>>dp(N,vector<ll>(N));
  vector<vector<bool>>b(N,vector<bool>(N,false));
  for(int i=0;i<N;i++)dp[i][i]=a[i];
  auto Y=[](auto f){
    return [=](auto&&... args){
      return f(f,forward<decltype(args)>(args)...);
    };
  };
  auto func=[&](auto f,int l,int r)->decltype(ll()){
    if(l>r)return 0;
    if(b[l][r])return dp[l][r];
    b[l][r]=true;
    ll res=0;
    int diff=N-(r-l+1);
    //(r-l)%2==0->
    if(diff%2){
    }
    else{
    }
    return res;
  };
  cout<<dp[0][N]<<endl;
  return 0;
}
