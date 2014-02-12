/*
 * 3280.cpp
 *
 * Last update: <2012年/12月/26日 00時23分55秒>
 */
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int dp[2010][2010];
int cost[256];

int main(int argc, char **argv){
  int N, M; cin >> N >> M;
  string s;
  cin >> s;
  for(int i = 0; i < N; i++){
    int a, b;
    char c;
    cin >> c >> a >> b;
    cost[c - 'a'] = min(a,b);
  }

  memset(dp, 0, sizeof(dp));
  
  for(int j = 1; j < M; j++){
    for(int i = j - 1; i >= 0; i--){
      dp[i][j] = min(cost[s[i] - 'a'] + dp[i + 1][j],
		     cost[s[j] - 'a'] + dp[i][j - 1]);
      if(s[i] == s[j])
	dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
    }
  }

  cout << dp[0][M - 1] << endl;
  return 0;
}