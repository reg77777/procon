#include <vector>
#include <cstdint>
#include <map>

using namespace std; //ごめんなさい

//エラストテネスの篩
vector<bool>eratosthenes(int n){
  vector<bool>res(n+1,true);
  res[0]=res[1]=false;
  for(int i=2;i<=n;i++){
    if(res[i])for(int j=i+i;j<=n;j+=i){
      res[j]=false;
    }
  }
  return res;
}
