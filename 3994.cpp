#include <cstdio>

int main(int argc, char **argv){
  int d, cnt = 0;
  while(scanf("%d", &d), d){
    printf("%d. %s %d\n", ++cnt, d % 2 ? "odd" : "even", d / 2);
  }
  return 0;
}
