// last update : 2013-03-11 22:21:33 nav

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

bool dp[850][850];
int seg[40];

double heron(double a, double b, double c){
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(int argc, char **argv){
  int n;
  while(cin >> n){
    int sum = 0;
    for(int i = 0; i < n; i++){
      cin >> seg[i];
      sum += seg[i];
    }
    int v = sum / 2;
    memset(dp, false,  sizeof(dp));
    dp[0][0] = true;
    for(int i = 0; i < n; i++){
      for(int j = v; j >= 0; j--){
	for(int k = v; k >= 0; k--){
	  if((j - seg[i] >= 0 && dp[j - seg[i]][k]) ||
	     (k - seg[i] >= 0 && dp[j][k - seg[i]]))
	    dp[j][k] = true;
	}
      }
    }

    int ans = -1;
    for(int j = 1; j <= v; j++){
      for(int k = 1; k <= v; k++){
	if(dp[j][k] && j + k > sum - j - k)
	  ans = max(ans, (int)(100 * heron(j, k, sum - j - k)));
      }
    }
    cout << ans << endl;
  }
}