// Time-stamp: <Sun Sep 11 23:37:17 東京 (標準時) 2016>
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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int N, E;
bool inside(int nx, int ny, int n2x, int n2y){
  return 0 <= ny && ny < N && 
	 0 <= nx && nx < E &&
	 0 <= n2y && n2y < N && 
	 0 <= n2x && n2x < E;
}
int main(int argc, char **argv){
  cin >> N >> E;
  N = 2 * N - 1;
  E = 2 * E - 1;
  vector<string> f(N);
  vector<vector<int> > prev(N, vector<int>(E, -1));
  for(int i = 0; i < N; i++) cin >> f[i];
  int sy, sx;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < E; j++)
      if(f[i][j] == 'S') sy = i, sx = j;
  prev[sy][sx] = INF;

  queue<int> Q;
  Q.push(sy * E + sx);
  int y, x;
  while(!Q.empty()){
    y = Q.front() / E;
    x = Q.front() % E;
    Q.pop();
    if(f[y][x] == 'E') break;
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i], nx = x + dx[i];
      int n2y = y + 2 * dy[i], n2x = x + 2 * dx[i];
      if(inside(nx, ny, n2x, n2y) && 
	 f[ny][nx] != '.' && f[n2y][n2x] != '.' && 
	 prev[n2y][n2x] == -1){
	prev[n2y][n2x] = y * E + x;
	Q.push(n2y * E + n2x);
      }
    }
  }
  string s;
  while(prev[y][x] != INF){
    int yy = prev[y][x] / E, xx = prev[y][x] % E;

    int dy = y - yy, dx = x - xx;
    if(dy == -2) s += "N";
    if(dy == 2) s += "S";
    if(dx == -2) s += "W";
    if(dx == 2) s += "E";

    y = yy, x = xx;
  }
  reverse(ALL(s));
  for(int i = 0; i < s.size(); ){
    char d = s[i++];
    int rep = 1;
    while(i < s.size() && d == s[i]){
      rep++; i++;
    } 
    cout << d << " " << rep << endl;
  }
  return 0;
}
