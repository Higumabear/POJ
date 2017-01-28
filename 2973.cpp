// Time-stamp: <Wed Jan 18 23:44:47 東京 (標準時) 2017>
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

string s[10001];
int main(int argc, char **argv){
  int n;
  while(cin >> n, n){
    for(int i = 0; i < n; i++){
      cin >> s[i];
      sort(ALL(s[i]));
    }
    string t;
    cin >> t;
    sort(ALL(t));
    
    int ans = 0;
    for(int k = 0; k < n; k++){
      int N = s[k].size(), M = t.size();
      int dp[8][8] = {0};
      for(int i = 0; i < N; i++){
	for(int j = 0; j < M; j++){
	  if(s[k][i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
	  else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
	}
      }
      ans += (N - dp[N][M] <= count(ALL(t), '_'));
    }
    cout << ans << endl;
  }
  return 0;
}
