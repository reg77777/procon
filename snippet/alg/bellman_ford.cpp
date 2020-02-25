#include<vector>

using namespace std; //‚²‚ß‚ñ‚È‚³‚¢

struct E{
  int to;
  int from;
  int cost;
};

vector<int>bellman_ford(vector<E>g,int n,int s,int inf){
  vector<int>d(n,inf);
  d[s]=0;
  for(int i=0;i<n-1;i++){
    for(auto e:g){
      if(d[e.from]==inf)continue;
      d[e.to]=min(d[e.to],d[e.from]+e.cost);
    }
  }
  for(auto e:g){
    if(d[e.from]==inf)continue;
    if(d[e.from]+e.cost<d[e.to])return vector<int>();
  }
  return d;
}
