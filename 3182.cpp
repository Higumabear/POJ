// Time-stamp: <Thu Nov 09 01:19:19 太平洋標準時 2017>
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

const int NUM = 100;
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int H, W;
int d[NUM][NUM];
char f[NUM][NUM];

int bfs(int sy, int sx, int gy, int gx){
  FILL(d, -1);
  d[sy][sx] = 0;
  queue<int> Q;
  Q.push(sy * W + sx);
  while(!Q.empty()){
    int y = Q.front() / W, x = Q.front() % W;
    Q.pop();
    if(gy == y && gx == x) return d[y][x];
    for(int k = 0; k < 8; k++){
      int ny = y + dy[k], nx = x + dx[k];
      if(0 <= ny && ny < H && 0 <= nx && nx < W &&
	 d[ny][nx] == -1 && f[ny][nx] == '.'){
	d[ny][nx] = d[y][x] + 1;
	Q.push(ny * W + nx);
      }
    }
  }
}


int add(int a, int b){
  if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}

struct P{
  int x, y;
  P() {}
  P(int x, int y) : x(x), y(y) {}
  P operator + (P p){
    return P(add(x, p.x), add(y, p.y));
  }
  P operator - (P p){
    return P(add(x, -p.x), add(y, -p.y));
  }
  P operator * (int d){
    return P(x * d, y * d);
  }
  int dot(P p){
    return add(x * p.x, y * p.y);
  }
  int det(P p){
    return add(x * p.y, -y * p.x);
  }
};

bool cmp_x(P a, P b){
  if(a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

vector<P> convex_hull(vector<P> &p){
  int N = p.size();
  sort(p.begin(), p.end(), cmp_x);
  int k = 0;
  vector<P> ret(N * 2);
  for(int i = 0; i < N; i++){
    while(k > 1 && (ret[k - 1] - ret[k - 2]).det(p[i] - ret[k - 1]) <= 0) k--;
    ret[k++] = p[i];
  }
  for(int i = N - 2, t = k; i >= 0; i--){
    while(k > t && (ret[k - 1] - ret[k - 2]).det(p[i] - ret[k - 1]) <= 0) k--;
    ret[k++] = p[i];
  }
  ret.resize(k - 1);
  return ret;
}

int main(int argc, char **argv){
  vector<P> p;
  cin >> H >> W;
  int sy, sx;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> f[i][j];
      if(f[i][j] == '*')
	sy = i, sx = j;
    }
  }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      for(int k = 0; k < 4; k++){
	int ny = i + dy[k], nx = j + dx[k];
	if(0 <= ny && ny < H && 0 <= nx && nx < W &&
	   f[ny][nx] == 'X'){
	  P tmp;
	  tmp.y = i, tmp.x = j;
	  p.push_back(tmp);
	  break;
	}
      }
    }
  }

  bfs(sy, sx, -1, -1);
  
  vector<P> ch = convex_hull(p);
  int M = ch.size();

  int round = 0;
  for(int i = 0; i < M; i++){
    f[ch[i].y][ch[i].x] = '@';
    round += max(abs(ch[i].y - ch[(i + 1) % M].y),
		 abs(ch[i].x - ch[(i + 1) % M].x));
  }

  int ans = INF;
  for(int i = 0; i < M; i++){
    int l = max(abs(ch[i].y - ch[(i + 1) % M].y),
		abs(ch[i].x - ch[(i + 1) % M].x));
    int hige = d[ch[i].y][ch[i].x]
      + d[ch[(i + 1) % M].y][ch[(i + 1) % M].x];
    //cout << l << " " << hige << " " << ch[i].x << " " << ch[i].y << " " << d[ch[i].y][ch[i].x] << endl;
    ans = min(ans, round - l + hige);
  }
  cout << ans << endl;
  // dump(ans);
  // dump(round);
  // for(int i = 0; i < H; i++){
  //   for(int j = 0; j < W; j++){
  //     cout << f[i][j];
  //   }
  //   cout << endl;
  // }
  return 0;
}