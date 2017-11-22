// Time-stamp: <Mon Mar 27 23:47:10 東京 (標準時) 2017>
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

int dx[] = {0, 1, 0, -1, 0};
int dy[] = {1, 0, -1, 0, 0};

bool goal[310][310], f[310][310];
int dist[310][310];
map<int, vector<pair<int, int> > > me;

int in(int y, int x){
  return 0 <= x && x < 310 && 0 <= y && y < 310;
}

int main(int argc, char **argv){
  int M;
  scanf("%d", &M);

  memset(f, true, sizeof(f));
  memset(goal, true, sizeof(goal));

  for(int i = 0; i < M; i++){
    int x, y, t;
    scanf("%d %d %d", &x, &y, &t);
    for(int j = 0; j < 5; j++){
      int ny = y + dy[j], nx = x + dx[j];
      if(in(ny, nx)){
	if(t == 0) f[ny][nx] = false;
	goal[ny][nx] = false;
      }
    }
    me[t].push_back(make_pair(y, x));
  }
  
  bool reach = false;
  FILL(dist, INF);
  queue<pair<int, int> > Q;
  if(f[0][0]) Q.push(make_pair(0, 0));
  dist[0][0] = 0;

  while(!Q.empty()){
    int y = Q.front().first, x = Q.front().second;
    int t = dist[y][x];
    Q.pop();
    if(goal[y][x]){
      printf("%d\n", t);
      reach = true;
      break;
    }
    if(me.count(t + 1)){
      vector<pair<int, int> > hit = me[t + 1];
      for(int i = 0; i < hit.size(); i++){
	for(int j = 0; j < 5; j++){
	  int ny = hit[i].first + dy[j], nx = hit[i].second + dx[j];
	  if(in(ny, nx)) f[ny][nx] = false;
	}
      }
    }
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(in(ny, nx) && f[ny][nx] && dist[ny][nx] == INF){
	dist[ny][nx] = t + 1;
	Q.push(make_pair(ny, nx));
      }
    }
  }

  if(!reach) puts("-1");
  return 0;
}
