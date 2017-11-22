#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[10010][510];
int D[10010];

int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++)
    scanf("%d", D + i);

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j <= M; j++){
      if(dp[i][j] == -1) continue;
      
      if(j != M)
	dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + D[i]);	
      if(j == 0)
	dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
      if(i + j <= N)
	dp[i + j][0] = max(dp[i + j][0], dp[i][j]);      
    }
  }
  printf("%d\n", dp[N][0]);
}
