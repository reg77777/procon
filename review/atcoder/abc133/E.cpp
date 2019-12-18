//木
//
//反省点:木に慣れておらず落ち着いて考えられなかった
#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,K;
  cin>>N>>K;
  vector<int>a(N-1),b(N-1);
  for(int i=0;i<N-1;i++)cin>>a[i]>>b[i];
  for(int i=0;i<N-1;i++)a[i]--,b[i]--;

  vector<vector<int>>v(N);
  for(int i=0;i<N-1;i++){
    v[a[i]].push_back(b[i]);
    v[b[i]].push_back(a[i]);
  }
  vector<bool>used(N,false);

  queue<int>q;
  int ans=K;
  used[0]=true;
  for(int i=0;i<v[0].size();i++){
    if(K-1-i<1){
      cout<<0<<endl;
      return 0;
    }
    ans=((ans%MOD)*max((K-1)-i,1ll))%MOD;
    used[v[0][i]]=true;
    q.push(v[0][i]);
  }
  while(q.size()>0){
    int x=q.front();
    q.pop();
    used[x]=true;
    int a=0;
    for(int i=0;i<v[x].size();i++){
      if(used[v[x][i]])continue;
      if(K-2-a<1){
        cout<<0<<endl;
        return 0;
      }
      ans=((ans%MOD)*max((K-2)-a,1ll))%MOD;
      q.push(v[x][i]);
      a++;
    }
  }
  cout<<ans%MOD<<endl;
  return 0;
}
