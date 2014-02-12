#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[10001];
int cow[10001];

int abs(int a){return (a > 0) ? a : -a;}
int main(int argc, char **argv){
  int N, L; scanf("%d %d", &N, &L);
  for(int i = 0; i < N; i++)
    scanf("%d", &cow[i]);

  int D = (L - N + 1) / N;
  int ND1 = L + 1 - N - (N - 1) * D;
  fill(dp, dp + 10001, 1 << 28);
  dp[0] = cow[0];
  for(int i = 1; i < N; i++){
    int dp_next[10001];
    fill(dp_next, dp_next + ND1 + 1, 1 << 28);
    for(int j = 0; j <= ND1; j++){
      int x = i + i * D + j;
      dp_next[j] = min(dp_next[j], dp[j] + abs(x - cow[i]));
      if(j < ND1)
	dp_next[j + 1] = min(dp_next[j + 1], dp[j] + abs(x + 1 - cow[i]));
    }
    copy(dp_next, dp_next + ND1 + 1, dp);
  }
  printf("%d\n", dp[ND1]);
  return 0;
}