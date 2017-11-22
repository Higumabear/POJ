// Time-stamp: <Tue Nov 07 21:35:16 東京 (標準時) 2017>
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

int f[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N;

bool C(int l, int u){
  if(f[0][0] < l || u < f[0][0]) return false;
  bool vis[101][101];
  FILL(vis, false);

  queue<int> Q;
  Q.push(0);
  vis[0][0] = true;
  while(!Q.empty()){
    int y = Q.front() / N, x = Q.front() % N;
    Q.pop();
    if(y == N - 1 && x == N - 1)
      return true;
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(0 <= ny && ny < N && 0 <= nx && nx < N && !vis[ny][nx]){
	if(l <= f[ny][nx] && f[ny][nx] < u){
	  vis[ny][nx] = true;
	  Q.push(ny * N + nx);
	}
      }
    }
  }
  return false;
}

bool check(int d){
  for(int i = 0; i + d <= 110; i++){
    if(C(i, i + d)) return true;
  }
  return false;
}

int main(int argc, char **argv){
  cin >> N;
  for(int i = 0; i <N; i++)
    for(int j = 0; j < N; j++)
      cin >> f[i][j];

  int ub = 110, lb = 0;
  while(lb < ub){
    int mid = (ub + lb) / 2;
    //dump(mid);
    if(check(mid)) ub = mid;
    else lb = mid + 1;
  }
  cout << ub-1 << endl;
  return 0;
}
