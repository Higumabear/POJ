#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
const int INF = 1 << 30;
const int M = 200002;

int dp[2][M];
int S[101], F[101];

int main(int argc, char **argv){
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> S[i] >> F[i];
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < M; j++)
      dp[i][j] = -INF;

  dp[0][100000] = 0;
  int *cur = dp[0], *next = dp[1];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(cur[j] != -INF){
	//Use S[i]
	next[j] = max(next[j], cur[j]);
	//Don't use S[i]
	next[j + S[i]] = max(next[j + S[i]], cur[j] + F[i]);
      }
    }
    swap(cur, next);
  }
  
  int ans = -INF;
  for(int i = 100000; i < M; i++)
    if(cur[i] >= 0)
      ans = max(ans, i - 100000 + cur[i]);

  cout << ans << endl;
  return 0;
}