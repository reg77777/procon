#include<vector>
#include<complex>

using namespace std;

vector<complex<double>>fft(vector<complex<double>>a,bool reverse=false){
  int N=a.size();
  double circle=2*3.1415926535;
  if(reverse)circle*=-1;
  if(N==1)return a;
  vector<complex<double>>b(N/2),c(N/2),res(N);
  for(int i=0;i<N;i++){
    if(i%2==0)b[i/2]=a[i];
    if(i%2==1)c[i/2]=a[i];
  }
  b=fft(b,reverse);
  c=fft(c,reverse);
  for(int i=0;i<N;i++)
    res[i]=b[i%(N/2)]+c[i%(N/2)]
      *exp(complex<double>(0,-circle*i/N));
  return res;
}

vector<complex<double>>ifft(vector<complex<double>>a){
  vector<complex<double>>res=fft(a,true);
  for(auto&it:res)it/=complex<double>(a.size());
  return res;
}
