// Time-stamp: <Thu Nov 10 22:25:13 東京 (標準時) 2016>
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

int f[40][40];
ll dp[40][40];
int main(int argc, char **argv){
  int N;
  while(cin >> N, N > 0){
    for(int k = 0; k < N; k++){
      string s; cin >> s;
      for(int i = 0; i < N; i++) 
	f[k][i] = (s[i] - '0');
    }
    FILL(dp, 0);
    dp[0][0] = 1;
    for(int y = 0; y < N; y++){
      for(int x = 0; x < N; x++){
	for(int i = y - 1; i >= 0; i--)
	  if(y - i == f[i][x]) dp[y][x] += dp[i][x];
	for(int i = x - 1; i >= 0; i--)
	  if(x - i == f[y][i]) dp[y][x] += dp[y][i];
      }
    }
    cout << dp[N - 1][N - 1] << endl;
  }
  return 0;
}
