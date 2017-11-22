// Time-stamp: <Sat Sep 23 02:17:29 東京 (標準時) 2017>
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

int W, H;
vector<string> f;
map<char, int> key;

bool hunt(){
  int sx, sy;
  for(int i = 0; i < H; i++)
    for(int j = 0; j < W; j++)
      if(f[i][j] == 'S') sx = j, sy = i;

  queue<int> Q;
  Q.push(sy * W + sx);
  vector<vector<bool> > vis(H, vector<bool>(W, false));
  vis[sy][sx] = true;
  while(!Q.empty()){
    int y = Q.front() / W, x = Q.front() % W;
    Q.pop();
    if(f[y][x] == 'G') return true;
    //dump(f[y][x]);
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(0 <= ny && ny < H && 0 <= nx && nx < W && !vis[ny][nx]){
	char c = f[ny][nx];
	if(c == 'X') continue;
	if('A' <= c && c <= 'E'){
	  if(key[(char)(c - 'A' + 'a')] == 0) f[ny][nx] = '.';
	  else continue;
	}
	if('a' <= c && c <= 'e'){
	  key[c]--;
	  f[ny][nx] = '.';
	}
	vis[ny][nx] = true;
	Q.push(ny * W + nx);
      }
    }
  }
  return false;
}

void pr(int idx){
  cout << string(10, '-') << endl;
  cout << idx << endl;
  for(int i = 0; i < H; i++) cout << f[i] << endl;
  cout << endl;
}

int main(int argc, char **argv){
  while(cin >> H >> W, W){
    key.clear();
    f.resize(H);
    for(int i = 0; i < H; i++) cin >> f[i];
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
	if('a' <= f[i][j] && f[i][j] <= 'e') 
	  key[f[i][j]]++;


    bool check = false;
    for(int i = 0; i < 1000; i++){
      if(hunt()){
	check = true;
	break;
      }
      //pr(i);
    }
    //pr(0);
    cout << (check ? "YES" : "NO") << endl;
  }
  return 0;
}
