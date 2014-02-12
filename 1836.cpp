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
typedef long long ll;

int dp1[1001];
int l[1001];
int dp2[1001];
int r[1001];
double h[1000];

void lis(int *dp, int *w, int N){
  int res = 0;
  for(int i = 0; i < N; i++){
    dp[i] = 1;
    for(int j = 0; j < i; j++){
      if(h[i] > h[j])
	dp[i] = max(dp[i], dp[j] + 1);
    }
    res = max(res, dp[i]);
    w[i] = res;
  }
}

int main(){
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> h[i];
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));

  lis(dp1, l, n);
  reverse(h, h + n);
  lis(dp2, r, n);
  reverse(r, r + n);

  int ans = 0;
  // for(int i = 0; i < n - 1; i++)
  //   for(int j = i + 1; j < n; j++)
  //     ans = max(ans, dp1[i] + dp2[j]);
  for(int i = 0; i < n - 1; i++)
    ans = max(ans, l[i] + r[i + 1]);

  cout << n - ans << endl;
  return 0;
}