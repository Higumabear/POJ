// Time-stamp: <Tue May 09 21:39:17 東京 (標準時) 2017>
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

struct rail{ 
  int w, f, c; 
  rail(int w, int f, int c):w(w),f(f),c(c){};
};

int dp[1001][1010];

int main(int argc, char **argv){
  int L, N, B;
  map<int, vector<rail> > q;
  scanf("%d %d %d", &L, &N, &B);
  for(int i = 0; i < N; i++){
    int x, w, f, c;
    scanf("%d %d %d %d", &x, &w, &f, &c);
    q[x].push_back(rail(w, f, c));
  }
  
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  map<int, vector<rail> >::iterator it = q.begin();
  for(; it != q.end(); it++){
    int cur = it->first;
    vector<rail> rails = it->second;
    for(int b = 0; b <= B; b++){
      if(dp[cur][b] == -1) continue;
      for(int i = 0; i < rails.size(); i++){
	int w = rails[i].w, f = rails[i].f, c = rails[i].c;
	int up = min(B + 1, b + c);
	dp[cur + w][up] = max(dp[cur + w][up], dp[cur][b] + f);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i <= B; i++)
    ans = max(ans, dp[L][i]);
  printf("%d\n", ans == 0 ? -1 : ans);
  return 0;
}
