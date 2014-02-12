/*
 * 1742.cpp
 *
 * Last update: <12/29/2012 05:01:22>
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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int dp[100001];
int A[100], C[100];

int main(){
  int n, m;
  while(cin >> n >> m){
    if(n == 0 && m == 0) break;

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> C[i];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= m; j++){
	if(dp[j] >= 0){
	  dp[j] = C[i];
	}else if(j < A[i] || dp[j - A[i]] <= 0){
	  dp[j] = -1;
	}else{
	  dp[j] = dp[j - A[i]] - 1;
	}
      }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++)
      if(dp[i] >= 0) ans++;

    cout << ans << endl;
  }
  return 0;
}