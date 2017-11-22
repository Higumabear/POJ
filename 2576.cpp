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

const int MAXN = 23000;

bool dp[MAXN + 1][52];
int p[100];

int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> p[i];
  sort(p, p + N);

  // N = 100;
  // fill(p, p + N, 450);

  memset(dp, false, sizeof(dp));

  dp[0][0] = true;
  for(int i = 0; i < MAXN; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k <= min(N / 2 + 1, j); k++){
	int v = min(i + p[j], MAXN);
	if(dp[i][k])
	  dp[v][k + 1] = dp[i][k];
	dp[i][k] = dp[i][k];
      }
    }
  }

  int ans = INF;
  int sum = accumulate(p, p + N, 0);
  for(int i = 0; i <= MAXN; i++){
    if(dp[i][N / 2]) 
      if(abs(ans - sum / 2) > abs(i - sum / 2))
	ans = i;
  }
  cout << min(ans, sum - ans) << " "
       << max(ans, sum - ans) << endl;
  return 0;
}
