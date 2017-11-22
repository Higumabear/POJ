// Time-stamp: <Thu May 11 23:31:47 東京 (標準時) 2017>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int dp[200][200];

int main(int argc, char **argv){
  string s, t;
  while(cin >> s >> t){
    FILL(dp, 0);
    dp[0][0] = 0;
    for(int i = 0; i < s.size(); i++){
      for(int j = 0; j < t.size(); j++){
	dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
	if(s[i] == t[j])
	  dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }
    
    string ans;
    int x = s.size(), y = t.size();
    while(x || y){
      if(x && dp[x][y] == dp[x - 1][y]){
	ans += s[--x];
      }else if(y && dp[x][y] == dp[x][y - 1]){
	ans += t[--y];
      }else{
	x--, y--;
	if(x >= 0) ans += s[x];
	else ans += t[y];
      }
    }
    reverse(ALL(ans));
    cout << ans << endl;
  }
  return 0;
}
