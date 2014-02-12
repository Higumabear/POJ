/*
 * 1953.cpp
 *
 * Last update: <05/16/2013 23:36:00>
 */

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
#define ALL(c) (c).begin(), (c).end()

using namespace std;
static const double EPS = 1e-8;
static const int INF = 1 << 29;
typedef long long ll;

ll dp[300][2];

int main(){
  int n; cin >> n;
  for(int k = 1; k <= n; k++){
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1, dp[1][1] = 1;
    
    int m;
    cin >> m;
    for(int i = 1; i < m; i++){
      dp[i + 1][0] += (dp[i][1] + dp[i][0]);
      dp[i + 1][1] += dp[i][0];
    }
    cout << "Scenario #" << k << ":" << endl;
    cout << dp[m][1] + dp[m][0] << endl;
    cout << endl;
  }
  return 0;
}
