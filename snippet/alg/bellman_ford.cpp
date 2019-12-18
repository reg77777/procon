//O(VE)
#include<vector>

struct E{
  int to;
  int from;
  int cost;
};

std::vector<int>bellman_ford(std::vector<E>&g,int v,int s,int inf){
  std::vector<int>d(v,inf);
  d[s]=0;
  for(int i=0;i<v-1;i++){
    for(auto e:g){
      if(d[e.from]==inf)continue;
      d[e.to]=std::min(d[e.to],d[e.from]+e.cost);
    }
  }
  for(auto e:g){
    if(d[e.from]==inf)continue;
    if(d[e.from]+e.cost<d[e.to])return std::vector<int>();
  }
  return d;
}
