#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

string a="abcdefghijklmnopqrstuvwxyz";

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin>>s;

  int c=0;
  char memo;
  for(int i=0;i<s.size();i++){
    if(s[i]==s[s.size()-i-1])c++;
    else memo=s[i];
  }
  return 0;
}
