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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int num[1010];
int dp[1001];

int main(){
  int n;
  cin >> n;
  
  fill(num, num + 1010, 0);
  fill(dp, dp + 1001, 0);

  for(int i = 0; i < n; i++) cin >> num[i];

  int res = 0;
  for(int i = 0; i < n; i++){
    dp[i] = 1;
    for(int j = 0; j < i; j++){
      if(num[j] < num[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
    res = max(res, dp[i]);
  }
  cout << res << endl;
  return 0;
}