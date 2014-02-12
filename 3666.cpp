// last update : 2013-03-20 00:31:55 nav

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

ll dp[2013][2013];

int main(int argc, char **argv){
  int N; cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  vector<int> b = a;
  ll ans = 1LL << 60;
  
  sort(b.begin(), b.end());
  fill(dp[0], dp[0] + N, 0);
  for(int i = 1; i <= N; i++)
    fill(dp[i], dp[i] + N, 1LL << 60);

  for(int i = 0; i < N; i++){
    ll mini = 1LL << 60;
    for(int j = 0; j < N; j++){
      dp[i + 1][j] = min(dp[i + 1][j], 
			 dp[i][j] + abs(a[i] - b[j]));
      if(a[i] >= b[j]){
	dp[i + 1][j] = min(dp[i + 1][j], 
			   mini + abs(a[i] - b[j]));
	mini = min(mini, dp[i][j]);
      }
    }
  }
  ans = min(ans, *min_element(dp[N], dp[N] + N));

  reverse(a.begin(), a.end());
  fill(dp[0], dp[0] + N, 0);
  for(int i = 1; i <= N; i++)
    fill(dp[i], dp[i] + N, 1LL << 60);

  for(int i = 0; i < N; i++){
    ll mini = 1LL << 60;
    for(int j = 0; j < N; j++){
      dp[i + 1][j] = min(dp[i + 1][j], 
			 dp[i][j] + abs(a[i] - b[j]));
      if(a[i] >= b[j]){
	dp[i + 1][j] = min(dp[i + 1][j], 
			   mini + abs(a[i] - b[j]));
	mini = min(mini, dp[i][j]);
      }
    }
  }
  cout << ans << endl;
}