// Time-stamp: <Wed Nov 08 09:58:48 太平洋標準時 2017>
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

int W, H;
int num;
int f[1010][1010];
int hy[1000100], hx[1000100];
int d[1010][1010];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int Q[1000100];

void bfs(int sy, int sx){
  int l = 0, r = 0;
  Q[0] = sy * W + sx;
  FILL(d, -1);
  d[sy][sx] = 0;
  while(l <= r){
    int y = Q[l] / W, x = Q[l] % W;
    l++;
    for(int k = 0; k < 4; k++){
      int ny = y + dy[k], nx = x + dx[k];
      if(0 <= ny && ny < H && 0 <= nx && nx < W &&
	 f[ny][nx] != 1 && d[ny][nx] == -1){
	d[ny][nx] = d[y][x] + 1;
	Q[++r] = ny * W + nx;
      }
    }
  }
}

int main(int argc, char **argv){
  scanf("%d %d", &W, &H);
  num = 0;
  int sx, sy, gx, gy;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      scanf("%d", &f[i][j]);
      if(f[i][j] == 2) sy = i, sx = j;
      if(f[i][j] == 3) gy = i, gx = j;
      if(f[i][j] == 4){
	hy[num] = i, hx[num] = j;
	num++;
      }
    }
  }
  vector<int> up, down;
  bfs(sy, sx);
  for(int i = 0; i < num; i++)
    up.push_back(d[hy[i]][hx[i]]);
  bfs(gy, gx);
  for(int i = 0; i < num; i++)
    down.push_back(d[hy[i]][hx[i]]);

  int ans = INF;
  for(int i = 0; i < num; i++)
    if(up[i] != -1 && down[i] != -1)
      ans = min(ans, up[i] + down[i]);
  printf("%d\n", ans);
  return 0;
}
