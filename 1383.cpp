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

int R, C;
char f[1001][1001];
int Q[1000001];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

char G[1000001];
int d[1000001];

void bfs(int idx){
  memset(d, -1, sizeof(d));

  int l = 0, r = 0;
  Q[l] = idx;
  d[idx] = 0;
  while(l <= r){
    int x = Q[l++];
    for(int k = 0; k < 4; k++){
      if(G[x] >> k & 1){
	int v = x + dy[k] * C + dx[k];
	if(d[v] == -1){
	  Q[++r] = v;
  	  d[v] = d[x] + 1;
  	}
      }
    }
  }
  // queue<int> Q;
  // Q.push(idx);
  // d[idx] = 0;
  // while(!Q.empty()){
  //   int x = Q.front(); Q.pop();
  //   for(int k = 0; k < 4; k++){
  //     if(G[x] >> k & 1){
  // 	int v = x + dy[k] * C + dx[k];
  // 	if(d[v] == -1){
  // 	  Q.push(v);
  // 	  d[v] = d[x] + 1;
  // 	}
  //     }
  //   }
  // }

  return;
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &C, &R);
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
	f[i][j] = getchar();
      }
      getchar();
    }
    memset(G, 0, sizeof(G));
    
    int start;
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
	if(f[i][j] == '.'){
	  start = i * C + j;
	  for(int k = 0; k < 4; k++){
	    int ny = i + dy[k], nx = j + dx[k];
	    if(0 <= ny && ny < R
	       && 0 <= nx && nx < C && f[ny][nx] == '.'){
	      G[i * C + j] |= 1 << k;
	    }
	  }
	}
      }
    }

    //dump(start);
    bfs(start);
    int fur = max_element(d, d + R * C) - d;
    //dump(fur);
    bfs(fur);
    int ans = *max_element(d, d + R * C);
    printf("Maximum rope length is %d.\n", ans);
  }
  return 0;
}
