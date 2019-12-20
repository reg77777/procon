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
  vector<int>a(N);
  for(int i=0;i<N;i++)cin>>a[i];
  int x=0,y=0,z=0;
  for(auto it:a){
    if(it==1)x++;
    if(it==2)y++;
    if(it==3)z++;
  }
  vector<vector<vector<double>>>
    dp(301,vector<vector<double>>(301,vector<double>(301,-1)));
  dp[0][0][0]=0;

  auto Y=[](auto f){
    return [=](auto&&... args){
      return f(f,forward<decltype(args)>(args)...);
    };
  };

  auto func=[&](auto f,double i,double j,double k)->decltype(double()){
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    double ret=0;
    if(i>0)ret+=f(f,i-1,j,k)*i;
    if(j>0)ret+=f(f,i+1,j-1,k)*j;
    if(k>0)ret+=f(f,i,j+1,k-1)*k;
    ret+=N;
    ret*=1./(i+j+k);
    dp[i][j][k]=ret;
    return ret;
  };

  cout<<fixed<<setprecision(20)<<Y(func)(x,y,z)<<endl;
  return 0;
}
