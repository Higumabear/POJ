#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

const int INF = 1 << 29;
const double EPS = 1e-7;

double dp[1005][101];

int main(int argc, char **argv){
  int C, N, M;
  while(scanf("%d", &C)){
    if(C == 0) break;
    scanf("%d %d", &N, &M);
    if(M > C || (N + M) % 2 == 1){
      printf("0.000\n");
    }else{
      if(N > 1000) N = 1000 + N % 2;
    
      memset(dp, 0, sizeof(dp));

      dp[0][0] = 1.0;
      for(int i = 1; i <= N; i++){
	memset(dp[i], 0, sizeof(dp[i]));
	for(int j = 0; j <= C; j++){
	  if(j - 1 >= 0)
	    dp[i][j] += dp[i - 1][j - 1] * (1.0 * (C - j + 1.0) / C); 
	  if(j + 1 <= C)
	    dp[i][j] += dp[i - 1][j + 1] * (1.0 * (j + 1.0) / C);
	}
      }
      printf("%.3lf\n", dp[N][M]);
    }
  }
  return 0;
}