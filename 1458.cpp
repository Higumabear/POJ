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
#include <cstring>
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

int dp[1001][1001];

int main(){
  string s, t;
  while(cin >> s >> t){
    memset(dp, 0, sizeof(dp));
    int N = s.length();
    int M = t.length();
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	if(s[i] == t[j])
	  dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
	else{
	  dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
	}
      }
    }
    cout << dp[N][M] << endl;
  }
  return 0;
}