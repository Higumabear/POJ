#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  int N, c;
  while(1){
    N = 0;
    while((c = getchar()) != '\n') N += (c - 48);
    if(N == 0) break;
    while(N >= 10){
      c = 0;
      while(N){
	c += (N % 10);
	N /= 10;
      }
      N = c;
    }
    printf("%d\n", N);
  }
  return 0;
}
