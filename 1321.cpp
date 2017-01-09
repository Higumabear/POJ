// Time-stamp: <Thu Dec 08 22:03:55 東京 (標準時) 2016>
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

using namespace std;

int N, K;
int ans;
char f[10][10];
void rec(int y, int x, int S){
  if(x == N){
    ans += (__builtin_popcount(S) == K);
    return;
  }
  if(f[y][x] == '#' && !(S >> y & 1))     
			rec(0, x + 1, S | (1 << y));
  if(y + 1 == N)	rec(0, x + 1, S);
  else			rec(y + 1, x, S);
  
  return;
}
int main(int argc, char **argv){
  while(cin >> N >> K){
    if(N == -1 && K == -1) break;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> f[i][j];
    ans = 0;
    rec(0, 0, 0);
    cout << ans << endl;
  }
  return 0;
}
