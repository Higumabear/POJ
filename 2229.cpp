/*
 * 2229.cpp
 *
 * Last update: <2012年/12月/22日 18時58分01秒>
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int dp[1000001];

int main(int argc, char **argv){
  int N;
  cin >> N;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for(int i = 1; i <= N; i *= 2){
    for(int j = 0; i + j <= N; j++){
      dp[i + j] += dp[j];
      dp[i + j] %= 1000000000;
    }
  }
  cout << dp[N] << endl;
  return 0;
}