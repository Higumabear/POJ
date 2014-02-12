#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv){
  int N, K;
  scanf("%d %d", &N, &K);
  for(int i = 0; i < K; i++){
    int S, T, R;
    scanf("%d %d %d", &S, &T, &R);
    
    printf("%d\n", (S + N - 1) / S + (N - 1) / (S * T) * R);
  }
  return 0;
}