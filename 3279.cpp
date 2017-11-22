// Time-stamp: <Mon Mar 13 01:03:56 東京 (標準時) 2017>
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

int M, N;
int init[15][15], sw[15][15], t[15][15];

inline void flip(int y, int x){
  t[y][x] = !t[y][x];
  if(0 <= y - 1)   t[y - 1][x] = !t[y - 1][x];
  if(0 <= x - 1)   t[y][x - 1] = !t[y][x - 1];
  if(y + 1 < M)   t[y + 1][x] = !t[y + 1][x];
  if(x + 1 < N)   t[y][x + 1] = !t[y][x + 1];  
}

int main(){
  cin >> M >> N;

  for(int i = 0; i < M; i++)
    for(int j = 0; j < N; j++){
      char c; cin >> c;
      init[i][j] = c == '1';
    }

  bool found = false;
  for(int S = 0; S < 1 << N; S++){
    FILL(sw, 0);
    //vector<vector<bool> > t = init;
    //memcpy(t, )
    for(int i = 0; i < M; i++)
      for(int j = 0; j < N; j++)
	t[i][j] = init[i][j];

    for(int j = 0; j < N; j++){
      if(S >> j & 1){
	flip(0, j);
	sw[0][j] = true;
      }
    }
      
    for(int i = 1; i < M; i++){
      for(int j = 0; j < N; j++){
	if(t[i - 1][j]){
	  flip(i, j);
	  sw[i][j] = true;
	}
      }
    }

    int cnt = 0;
    for(int i = 0; i < M; i++)
      for(int j = 0; j < N; j++)      
	cnt += t[i][j];
      
    if(cnt == 0){
      for(int i = 0; i < M; i++){
	for(int j = 0; j < N; j++)
	  cout << sw[i][j] << " ";
	cout << endl;
      }
      found = true;
      break;
    }
  }
  if(!found) cout << "IMPOSSIBLE" << endl;
}
