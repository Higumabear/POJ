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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int n;
ll dp[100];
int main(){
  dp[0] = 1, dp[2] = 3;
  for(int i = 4; i < 100; i += 2) dp[i] = 4 * dp[i - 2] - dp[i - 4];
  for(;cin >> n; cout << dp[n] << endl) if(n == -1) break;
  return 0;
}
