#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char **argv){
  int n;
  printf("PERFECTION OUTPUT\n");
  while(scanf("%d", &n), n){
    int cnt = 0;
    for(int i = 1; i * i <= n; i++){
      if(n % i == 0)
	cnt = cnt + i + ((i != 1 && i * i != n) ? n / i : 0);
    }
    if(n == 1) cnt--;
    if(cnt < n)		printf("%5d  DEFICIENT\n", n);
    else if(cnt > n)	printf("%5d  ABUNDANT\n", n);
    else		printf("%5d  PERFECT\n", n);
  }
  printf("END OF OUTPUT\n");
}