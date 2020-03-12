#include <vector>
#include <cstdint>

using namespace std;

struct Doubling{
  vector<vector<int>>table;
  int log;
  int sz;
  //sz:要素数 lim:最大の数
  Doubling(int sz,int64_t lim):sz(sz),log(64-__builtin_clzll(lim)){
    table.resize(sz,vector<int>(log,-1));
  }
  void set_next(int now,int next){
    table[now][0]=next;
  }
  void build(){
    for(int j=0;j<log-1;j++){
      for(int i=0;i<sz;i++){
        if(table[i][j]==-1)table[i][j+1]=-1;
        else table[i][j+1]=table[table[i][j]][j]; //iの2^j先の2^j先->iの2^(j+1)先
      }
    }
  }
  int query(int x,int64_t t){
    for(int i=log-1;i>=0;i--){
      if((t>>i)&1)x=table[x][i];
    }
    return x;
  }
};
