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

int dp[60][60][16];
int dx[6] = {-1, -1, 0, 1, 1, 0};
int dy[6] = {0, -1, -1, 0, 1, 1};

int cur(int x, int y, int num){
  if(num == 0){
    if(x == 30 && y == 30) return 1;
    return 0;
  }
  if(dp[x][y][num] != -1) return dp[x][y][num];

  int ret = 0;
  for(int i = 0; i < 6; i++){
    ret += cur(x + dx[i], y + dy[i], num - 1);
  }
  return dp[x][y][num] = ret;
}

int main(){
  int T;
  cin >> T;
  memset(dp, -1, sizeof(dp));
  while(T--){
    int n;
    cin >> n;
    cout << cur(30, 30, n) << endl;;
  }
  return 0;
}