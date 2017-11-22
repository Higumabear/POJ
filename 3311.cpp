// Time-stamp: <Tue Apr 11 00:08:29 東京 (標準時) 2017>
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

int V;
int dp[11][1 << 11];
int d[11][11];


int main(int argc, char **argv){
  while(cin >> V, V){
    V++;
    for(int i = 0; i < V; i++)
      for(int j = 0; j < V; j++)
	cin >> d[i][j];
    FILL(dp, INF);
    
    dp[0][0] = 0;
    for(int j = 0; j < 1 << V; j++)
      for(int m = 0; m < V; m++)
	for(int i = 0; i < V; i++)
	  for(int k = 0; k < V; k++)
	    dp[k][j | 1 << k] = min(dp[k][j | 1 << k], dp[i][j] + d[i][k]);
    cout << dp[0][(1 << V) - 1] << endl;
  }
  return 0;
}
