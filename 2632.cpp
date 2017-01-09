// Time-stamp: <Sun Dec 25 16:06:34 東京 (標準時) 2016>
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
int p[101][101];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void debug(){
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cout << p[i][j] << "\t"; 
    }
    cout << endl;
  }
}

bool inside(int y, int x){
  return 0 <= x && x < W && 0 <= y && y < H;
}
int main(int argc, char **argv){
  int T; scanf("%d", &T);
  map<char, int> f;
  f['N'] = 0, f['E'] = 1, f['S'] = 2, f['W'] = 3;
  while(T--){
    scanf("%d %d", &W, &H);
    int N, M; scanf("%d %d", &N, &M);
    vector<int> pos;
    FILL(p, -1);
    for(int i = 0; i < N; i++){
      int y, x;
      char dir;
      scanf("%d %d %c", &x, &y, &dir);
      y--, x--;
      p[y][x] = i;
      pos.push_back(100 * 100 * y + 100 * x + f[dir]);
    }
    for(int i = 0; i < M; i++){
      //debug();
      int idx, b;
      char a;
      scanf("%d %c %d", &idx, &a, &b);
      int y = pos[idx - 1] / 10000;
      int x = (pos[idx - 1] % 10000) / 100;
      int direc = pos[idx - 1] % 100;
      pos[idx - 1] = 0;
      p[y][x] = -1;
      if(a == 'F'){
	for(int j = 0; j < b; j++){
	  y += dy[direc];
	  x += dx[direc];
	  if(!inside(y, x)){
	    cout << "Robot " << idx << " crashes into the wall" << endl;
	    while(++i < M) cin >> idx >> a >> b;
	    goto L1;
	  }
	  if(p[y][x] != -1){
	    cout << "Robot " << idx << " crashes into robot " 
		 << p[y][x]  + 1 <<endl;
	    while(++i < M) cin >> idx >> a >> b;
	    goto L1;
	  }
	}
	p[y][x] = idx - 1;
	pos[idx - 1] = 10000 * y + 100 * x + direc;
      }else{
	if(a == 'L') direc = (direc - b + 40000) % 4;
	if(a == 'R') direc = (direc + b) % 4;
	p[y][x] = idx - 1;
	pos[idx - 1] = 10000 * y + 100 * x + direc;
      }
    }
    cout << "OK" << endl;
  L1:;
  }
  return 0;
}
