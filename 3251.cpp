// Time-stamp: <Wed Nov 08 22:59:44 太平洋標準時 2017>
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

int N;
int num;
int by, bx;
int jy[10000], jx[10000];
char f[100][100];

inline bool in(int y, int x){
  return 0 <= y && y < N && 0 <= x && x < N;
}

inline bool sign(int x){
  return x >= 0;
}

inline bool contain(int ay, int ax, int by, int bx,
		  int cy, int cx, int dy, int dx,
		  int y, int x){
  bool ab = sign(-(x - ax) * (by - ay) + (y - ay) * (bx - ax));
  bool bc = sign(-(x - bx) * (cy - by) + (y - by) * (cx - bx));
  bool cd = sign(-(x - cx) * (dy - cy) + (y - cy) * (dx - cx));
  bool da = sign(-(x - dx) * (ay - dy) + (y - dy) * (ax - dx));
  return ab && bc && cd && da;
}

int main(int argc, char **argv){
  cin >> N;
  num = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      char x;
      cin >> x;
      if(x == 'J'){
	jy[num] = i, jx[num] = j;
	num++;
      }
      f[i][j] = x;
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(f[i][j] == 'B') continue;
      for(int k = num - 1; k >= 0; k--){
	if(ans > (jy[k] - i) * (jy[k] - i) +
	   (jx[k] - j) * (jx[k] - j)) continue;
	int py, px, qy, qx;
	px = -jy[k] + i + j, py = jx[k] - j + i;
	qx = jx[k] - jy[k] + i, qy = jy[k] + jx[k] - j;
	if(in(py, px) && in(qy, qx)
	   // && !contain(i, j, jy[k], jx[k],
	   // 	       qy, qx, py, px, by, bx)
	   && f[py][px] == 'J' && f[qy][qx] == 'J')
	  ans = max(ans,
		    (jy[k] - i) * (jy[k] - i) +
		    (jx[k] - j) * (jx[k] - j));

	px = jy[k] - i + j, py = -jx[k] + j + i;
	qx = jx[k] + jy[k] - i, qy = jy[k] - jx[k] + j;
	if(in(py, px) && in(qy, qx)
	   // && !contain(i, j, jy[k], jx[k],
	   // 	       qy, qx, py, px, by, bx)
	   && f[py][px] == 'J' && f[qy][qx] == 'J')
	  ans = max(ans,
		    (jy[k] - i) * (jy[k] - i) +
		    (jx[k] - j) * (jx[k] - j));
	
      }
    }
  }
  cout << ans << endl;
  return 0;
}
