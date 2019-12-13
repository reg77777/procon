//二分探索
//反省点 細部が雑だった
//
//A[i]*F[i]>mが一個あればだめだと勘違いした

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

  ll N,K;
  cin>>N>>K;
  vector<ll>A(N),F(N);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++)cin>>F[i];
  sort(rng(A));
  sort(rng(F));
  reverse(rng(F));
  ll l=-1;
  ll r=pow(10,12);
  ll m;
  while(r-l>1){
    m=(l+r)/2;
    ll c=0;
    for(int i=0;i<N;i++){
      if(A[i]*F[i]>m){
        c+=A[i]-m/F[i];
      }
      if(c>K)break;
    }
    if(c>K)l=m;
    else r=m;
  }
  cout<<r<<endl;
  return 0;
}
