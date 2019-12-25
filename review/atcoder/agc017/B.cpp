//全探索
//
//反省点:特になし
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

  ll N,A,B,C,D;
  cin>>N>>A>>B>>C>>D;
  int d=abs(A-B);
  bool ok=false;
  for(int i=0;i<N;i++){
    ll Up=D*(N-1-i)-C*i;
    ll Down=C*(N-1-i)-D*i;
    if(Down<=d&&d<=Up)ok=true;
  }
  if(ok)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
