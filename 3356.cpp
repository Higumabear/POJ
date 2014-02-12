#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int dp[1001][1001];
int main(int argc, char **argv){
  int M, N;
  string s, t;
  while(cin >> M >> s >> N >> t){
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= M; i++)
      dp[i][0] = i;
    for(int j = 0; j <= N; j++)
      dp[0][j] = j;

    for(int i = 0; i < M; i++){
      for(int j = 0; j < N; j++){
	int cost = (s[i] == t[j]) ? 0 : 1;
	dp[i + 1][j + 1] = min(dp[i + 1][j] + 1,
			       min(dp[i][j + 1] + 1,
				   dp[i][j] + cost));
      }
    }
    cout << dp[M][N] << endl;
  }
  return 0;
}