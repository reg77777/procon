#include <vector>
#include <cstdint>
#include <map>

using namespace std; //$B$4$a$s$J$5$$(B

//$B%(%i%9%H%F%M%9$NdA(B
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
