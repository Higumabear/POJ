// Time-stamp: <Thu Aug 04 22:06:22 東京 (標準時) 2016>
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

int N;
int f[101][101];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void rec(int y, int x, int idx){
  f[y][x] = -1;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i], nx = x + dx[i];
    if(0 <= nx && nx < N && 0 <= ny && ny < N && 
       f[ny][nx] == idx)
      rec(ny, nx, idx);
  }
}
 
int main(int argc, char **argv){
  while(cin >> N, N){
    memset(f, -1, sizeof(f));
    for(int i = 0; i < N - 1; i++){
      for(int j = 0; j < N; j++){
	int y, x; cin >> y >> x;
	f[y - 1][x - 1] = i;
      }
    }

    for(int i = 0; i < N * N; i++)
      if(f[i / N][i % N] == -1) f[i / N][i % N] = N - 1;

    for(int i = 0; i < N; i++){
      for(int y = 0; y < N; y++)
	for(int x = 0; x < N; x++)
	  if(f[y][x] == i){
	    rec(y, x, i);
	    goto L1;
	  }
    L1:;
    }
    bool good = true;
    for(int y = 0; y < N; y++)
      for(int x = 0; x < N; x++)
	if(f[y][x] != -1) good = false;
    cout << (good ? "good" : "wrong") << endl;
  }
  return 0;
}
