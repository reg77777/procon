#include <bits/stdc++.h>
using namespace std;

struct E{int to,from,cost;};

template<typename T,T inf>
vector<T>bellman_ford(vector<E>&g,int s,int sz){
  vector<T>d(sz,inf);
  d[s]=0;
  for(int i=0;i<sz-1;i++)for(auto e:g)if(d[e.from]!=inf)d[e.to]=min(d[e.to],d[e.from]+e.cost);
  for(auto e:g)if(d[e.from]!=inf&&d[e.from]+e.cost<d[e.to])return vector<T>();
  return d;
}
