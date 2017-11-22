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

int d[30][30];
int dp[30][30][30][30];

int main(){
  int M; cin >> M;
  while(M--){
    int N;
    cin >> N;
    FILL(d, INF);
    for(int i = 0; i < N - 1; i++)
      for(int j = 0; j < N - 1 - i; j++)
	cin >> d[i][j + i + 1];

    FILL(dp, INF);
    dp[0][0][0][0] = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < i; j++){
	for(int a = 0; a < i; a++){
	  for(int b = 0; b < i; b++){
	    for(int c = 0; c < i; c++){
	      dp[i][i][b][c] = min(dp[i][i][b][c],
				   dp[i-1][j][b][c] + d[j][i]);
	      dp[i][a][i][c] = min(dp[i][a][i][c],
				   dp[i-1][a][j][c] + d[j][i]);
	      dp[i][a][b][i] = min(dp[i][a][b][i],
				   dp[i-1][a][b][j] + d[j][i]);
	    }
	  }
	}
      }
    }
    int ans = INF;
    for(int b = 0; b < N; b++)
      for(int c = 0; c < N; c++)
	ans = min(ans, dp[N - 1][N - 1][b][c]);
    for(int a = 0; a < N; a++)
      for(int b = 0; b < N; b++)
	ans = min(ans, dp[N - 1][a][b][N - 1]);
    for(int a = 0; a < N; a++)
      for(int c = 0; c < N; c++)
	ans = min(ans, dp[N - 1][a][N - 1][c]);
    cout << ans << endl;
  }  
  return 0;
}
