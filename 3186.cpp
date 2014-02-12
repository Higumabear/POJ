#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int dp[2001][2001];
int v[2001];

int main(int argc, char **argv){
  memset(dp, 0, sizeof(dp));
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];

  dp[0][1] = v[n - 1];
  dp[1][0] = v[0];

  for(int i = 0; i <= n; i++){
    for(int j = 0; i + j <= n; j++){
      if(i - 1 < 0){
	dp[i][j] = (i + j) * v[n - j] + dp[i][j - 1];
      }else if(j - 1 < 0){
	dp[i][j] = (i + j) * v[i - 1] + dp[i - 1][j];
      }else{
	dp[i][j] = max((i + j) * v[i - 1] + dp[i - 1][j],
		       (i + j) * v[n - j] + dp[i][j - 1]);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++)
    ans = max(ans, dp[i][n - i]);

  cout << ans << endl;
  return 0;
}