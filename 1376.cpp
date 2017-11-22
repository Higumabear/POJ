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

int H, W;
int sy, sx, gy, gx;
string dir;
bool f[60][60];
int d[60][60][4];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool in(int y, int x){
  if(0 < y && y < H && 0 < x && x < W){
    if(!f[y][x] && !f[y - 1][x - 1] &&
       !f[y - 1][x] && !f[y][x - 1]){
      return true;
    }
  }
  return false;
}

int main(){
  while(cin >> H >> W, H){
    for(int i = 0; i < H * W; i++){
      int v; cin >> v;
      f[i / W][i % W] = v == 1;
    }
    cin >> sy >> sx >> gy >> gx >> dir;

    FILL(d, INF);
    int c;
    if(dir == "north") c = 0;
    if(dir == "east") c = 1;
    if(dir == "south") c = 2;
    if(dir == "west") c = 3;
    queue<pair<int, int> > Q;
    Q.push(make_pair(sy * W + sx, c));
    d[sy][sx][c] = 0;
    while(!Q.empty()){
      int y = Q.front().first / W,
	x = Q.front().first % W,
	c = Q.front().second;
      Q.pop();

      if(y == gy && x == gx) break;
      
      for(int k = 1; k <= 3; k++){
	int ny = y + k * dy[c], nx = x + k * dx[c];
	if(in(ny, nx)){
	  if(d[ny][nx][c] == INF){
	    Q.push(make_pair(ny * W + nx, c));
	    d[ny][nx][c] = d[y][x][c] + 1;
	    
	    // cout << y << " " << x << " -> "
	    //      << ny << " " << nx << " : "
	    //      << d[ny][nx][c] << endl;
	  }
	}else break;
      }
      if(d[y][x][(c + 1) % 4] == INF){
	Q.push(make_pair(y * W + x, (c + 1) % 4));
	d[y][x][(c + 1) % 4] = d[y][x][c] + 1;
      }
      if(d[y][x][(c + 3) % 4] == INF){
	Q.push(make_pair(y * W + x, (c + 3) % 4));
	d[y][x][(c + 3) % 4] = d[y][x][c] + 1;
      }      
    }
    //dump(c);
    int ans = INF;
    for(int s = 0; s < 4; s++)
      ans = min(ans, d[gy][gx][s]);
    cout << (ans >= INF ? -1 : ans) << endl;
  }
  return 0;
}
