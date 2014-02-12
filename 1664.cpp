/*
 * 1664.cpp
 *
 * Last update: <2012年/12月/17日 00時40分17秒>
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int dp[11][11];

int main(int argc, char **argv){
  int t;
  cin >> t;

  while(t--){
    int N, M; cin >> N >> M;

    for(int i = 0; i <= 10; i++) dp[0][i] = 1;
    for(int i = 0; i <= 10; i++) dp[i][1] = 1;
    
    for(int i = 1; i <= 10; i++){
      for(int j = 2; j <= 10; j++){
	dp[i][j] = dp[i][j - 1];
	if(i >= j)
	  dp[i][j] += dp[i - j][j];
      }
    }

    cout << dp[N][M] << endl;
  }
  return 0;
}