// Time-stamp: <Sat Jan 07 00:51:41 東京 (標準時) 2017>
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
bool vis[30][30];
int path[30][2];
int dy[] = {-2,-2,-1,-1,1,1,2,2};
int dx[] = {-1,1,-2,2,-2,2,-1,1};

bool rec(int y, int x, int len){
  if(len == H * W) return true;
  else{
    int i, ny, nx;
    for(i = 0; i < 8; i++){
      ny = y + dy[i], nx = x + dx[i];
      if(0 <= ny && ny < H && 0 <= nx && nx < W && !vis[ny][nx]){
	vis[ny][nx] = true;
	if(rec(ny, nx, len + 1)){
	  path[len][0] = ny, path[len][1] = nx;
	  return true;
	}
	vis[ny][nx] = false;
      }
    }
  }
  return false;
}
int main(int argc, char **argv){
  int T; cin >> T;
  for(int t = 1; t <= T; t++){
    scanf("%d %d", &W, &H);
    FILL(vis, false);
    vis[0][0] = true;
    printf("Scenario #%d:\n", t);
    if(rec(0, 0, 1)){
      for(int i = 0; i < H * W; i++){
	printf("%c%d", path[i][0] + 'A', path[i][1] + 1);
      }
      puts("");
    }else{
      printf("impossible\n");
    }
    if(t != T) puts("");
  }
  return 0;
}
