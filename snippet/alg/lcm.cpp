long long int gcd(long long int a,long long int b){
  if(a==0)return b;
  return gcd(b%a,b);
}

long long int lcm(long long int a,long long int b){
  return a*b/gcd(a,b);
}
