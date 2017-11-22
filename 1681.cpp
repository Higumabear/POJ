// Time-stamp: <Sat Mar 18 01:07:29 東京 (標準時) 2017>
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
int f[15][15];
int c[15][15];

void flip(int y, int x){
  c[y][x] = !c[y][x];
  if(0 < y) c[y-1][x] = !c[y-1][x];
  if(0 < x) c[y][x-1] = !c[y][x-1];
  if(y < N - 1) c[y+1][x] = !c[y+1][x];
  if(x < N - 1) c[y][x+1] = !c[y][x+1];
}

int main(int argc, char **argv){
  int T;
  cin >> T;
  while(T--){
    cin >> N;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
	char t; cin >> t;
	f[i][j] = t == 'y';
      }
    }
    
    int ans = INF;
    for(int S = 0; S < 1 << N; S++){
      memcpy(c, f, sizeof(f));
      for(int i = 0; i < N; i++)
	if(S >> i & 1) flip(0, i);
      
      int cnt = __builtin_popcount(S);
      for(int i = 1; i < N; i++){
	for(int j = 0; j < N; j++){
	  if(!c[i - 1][j]){
	    cnt++;
	    flip(i, j);
	  }
	}
      }
      bool check = true;
      for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)       
	  check &= c[i][j];
      if(check) ans = min(ans, cnt);
    }
    if(ans == INF)
      cout << "inf" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
