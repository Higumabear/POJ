// Time-stamp: <Mon Aug 15 21:35:15 東京 (標準時) 2016>
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
int d[1010][1010];

int main(int argc, char **argv){
  int X, Y, N;
  scanf("%d %d %d", &X, &Y, &N);
  X += 500, Y += 500;

  FILL(d, -1);
  for(int i = 0; i < N; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    d[y + 500][x + 500] = INF;
  }

  d[500][500] = 0;
  queue<pair<int, int> > Q;
  Q.push(make_pair(500, 500));
  while(!Q.empty()){
    int y = Q.front().first, x = Q.front().second;
    Q.pop();
    if(Y == y && X == x){
      cout << d[y][x] << endl;
      return 0;
    }
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(0 <= ny && ny <= 1000 && 0 <= nx && nx <= 1000 && 
	 d[ny][nx] == -1){
	d[ny][nx] = d[y][x] + 1;
	Q.push(make_pair(ny, nx));
      }
    }
  }
  return 0;
}