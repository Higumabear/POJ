// last update : 2013-03-13 01:32:41 nav

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

int N, K;
int apple[101];
vector<int> node[101];
int dp[2][1010][201];
bool used[1010];

void dfs(int s){
  used[s] = true;
  for(int i = 0; i <= K; i++)
    dp[0][s][i] = dp[1][s][i] = apple[s];
  for(int i = 0; i < (int)node[s].size(); i++){
    int t = node[s][i];
    if(used[t]) continue;
    dfs(t);
    for(int j = K; j >= 0; j--){
      for(int k = 0; k <= j; k++){
	dp[0][s][j + 2] = max(dp[0][s][j + 2], dp[0][t][k] + dp[0][s][j - k]);	
	dp[1][s][j + 2] = max(dp[1][s][j + 2], dp[0][t][k] + dp[1][s][j - k]);
	dp[1][s][j + 1] = max(dp[1][s][j + 1], dp[1][t][k] + dp[0][s][j - k]);
      }
    }
  }
}

int main(int argc, char **argv){
  while(cin >> N >> K){
    for(int i = 0; i < N; i++) cin >> apple[i];
    for(int i = 0; i < 101; i++) node[i].clear();
    for(int i = 0; i < N - 1; i++){
      int a, b;
      cin >> a >> b;
      node[a - 1].push_back(b - 1);      
      node[b - 1].push_back(a - 1);
    }
    memset(dp, 0, sizeof(dp));
    memset(used, false, sizeof(used));
    dfs(0);
    cout << dp[1][0][K] << endl;
  }
}