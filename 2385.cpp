#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][31];
int a[1000];

int main(){
  int T, W;
  cin >> T >> W;

  for(int i = 0; i < T; i++){
    cin >> a[i];
    a[i]--;
  }

  memset(dp, 0, sizeof(dp));

  for(int i = 0; i < T; i++){
    for(int j = 0; j < W; j++){
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1],
			     dp[i][j] + (a[i] == ((j + 1) & 1)));
      dp[i + 1][j] = max(dp[i + 1][j],
			 dp[i][j] + (a[i] == (j & 1)));
    }
    dp[i + 1][W] = max(dp[i+1][W], dp[i][W] + (a[i]==(W & 1)));
  }

  int ret = 0;
  for(int i = 0; i <= W; i++){
    ret = max(ret, dp[T][i]);
  }
  cout << ret << endl;
}
