//二分探索
//
//反省点:落ち着いて丁寧に考えられなかった
//良かった点:方針自体はあってた
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

  ll N,M,V,P;
  cin>>N>>M>>V>>P;
  vector<ll>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  sort(rng(A));
  reverse(rng(A));
  ll l=0;
  ll r=N;
  ll m;
  while(r-l>1){
    m=(l+r)/2;
    ll sum=0;
    vector<ll>B=A;
    ll AA=A[m]+M;
    ll VV=V*M-M;
    B[m]=AA;
    for(int i=0;i<N;i++){
      if(i==m)continue;
      VV-=min(max(AA-B[i],0ll),M);
      B[i]=min(max(AA,B[i]),B[i]+M);
      if(VV<=0)break;
    }
    for(int i=0;i<N;i++){
      if(i==m)continue;
      ll D=M-(B[i]-A[i]);
      if(D<=0)continue;
      B[i]+=min(VV,D);
      VV=max(VV-D,0ll);
      if(VV<=0)break;
    }
    ll c=0;
    for(auto it:B)if(it>AA)c++;
    if(c<P)l=m;
    else r=m;
  }
  cout<<l+1<<endl;
  return 0;
}
