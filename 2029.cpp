// Time-stamp: <Fri Apr 14 21:08:58 東京 (標準時) 2017>
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

int N, W, H, S, T;
bool f[210][210];
int sum[210][210];


int main(int argc, char **argv){
  while(scanf("%d", &N), N){
    FILL(f, false);
    FILL(sum, 0);

    scanf("%d %d", &W, &H);
    for(int i = 0; i < N; i++){
      int x, y;
      scanf("%d %d", &x, &y);
      f[x][y] = true;
    }
    scanf("%d %d", &S, &T);

    for(int x = 1; x <= W; x++)
      for(int y = 1; y <= H; y++)
	sum[x][y] = f[x][y] + sum[x - 1][y] 
	  + sum[x][y - 1] - sum[x - 1][y - 1];

    int ans = 0;
    for(int x = 1; x + S - 1 <= W; x++){
      for(int y = 1; y + T - 1 <= H; y++){    
	int a = sum[x + S - 1][y + T - 1];
	int b = sum[x - 1][y + T - 1];
	int c = sum[x + S - 1][y - 1];
	int d = sum[x - 1][y - 1];
	ans = max(ans, a - b - c + d);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
