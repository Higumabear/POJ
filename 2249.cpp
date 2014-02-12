#include <cstdio>
#include<iostream>
using namespace std;

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m) && n){
    if(n - m < m)
      m = n - m;
    __int64 ans = 1, cou = m;
    while(cou --){
      ans *= n --;
      while(ans % m == 0 && m > 1)
	ans /= m --;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}