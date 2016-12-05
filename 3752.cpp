// Time-stamp: <Sat Oct 29 03:57:45 東京 (標準時) 2016>
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

char f[500][500];
int main(int argc, char **argv){
  int H, W;
  scanf("%d %d", &H, &W);

  int dy[] = {0, -1, 0, 1};
  int dx[] = {1, 0, -1, 0};

  int cnt = 1;
  int k = 0;
  FILL(f, '.');
  int y = 0, x = 0;
  f[y][x] = 'A';
  while(cnt < H * W){
    int ny = y + dy[k];
    int nx = x + dx[k];
    if(0 <= ny && ny < H && 0 <= nx && nx < W ){
      if(f[ny][nx] == '.'){
	f[ny][nx] = (char)(cnt % 26 + 'A');
	cnt++;
	y = ny, x = nx;
      }else
	k = (k + 1) % 4;
    }else
      k = (k + 1) % 4;
  }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++)
      printf("   %c", f[i][j]);
    printf("\n");
  }
  return 0;
}
