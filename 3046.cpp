#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
static const int MOD = 1000000;
typedef long long ll;

int a[1000];

int main(){
  int T, A, S, B;
  memset(a, 0, sizeof(a));
  scanf("%d %d %d %d", &T, &A, &S, &B);
  for(int i = 0; i < A; i++){
    int t;
    scanf("%d", &t);
    a[t - 1]++;
  }

  vector<vector<int> > dp(T + 1, vector<int>(B + 1, 0));

  for(int i = 0; i <= T; i++)
    dp[i][0] = 1;

  for(int i = 0; i < T; i++){
    for(int j = 1; j <= B; j++){
      if(j - 1 - a[i] >= 0)
	dp[i + 1][j] = (dp[i + 1][j - 1]
			+ dp[i][j] - dp[i][j - 1 - a[i]]
			+ MOD) % MOD;
      else
	dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
    }
  }

  int ans = 0;
  for(int i = S; i <= B; i++)
    ans += dp[T][i];

  cout << ans % MOD << endl;
  return 0;
}