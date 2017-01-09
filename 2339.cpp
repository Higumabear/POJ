// Time-stamp: <Sun Jan 08 16:15:21 東京 (標準時) 2017>
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

char cur[2][110][110];
bool lose(char s, char t){
  return (t == 'R' && s == 'S') || 
    (t == 'S' && s == 'P') || 
    (t == 'P' && s == 'R');
}
char chg(char c){
  if(c == 'R') return 'P';
  if(c == 'S') return 'R';
  if(c == 'P') return 'S';
}
int main(int argc, char **argv){
  int T; cin >> T;
  for(int t = 0; t < T; t++){
    int H, W, N;
    cin >> H >> W >> N;
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++) cin >> cur[0][i][j];
    for(int k = 0; k < N; k++){
      int r = k % 2;
      for(int i = 0; i < H; i++){
	for(int j = 0; j < W; j++){
	  bool safe = true;
	  for(int p = 0; p < 4; p++){
	    int nx = j + dx[p], ny = i + dy[p];
	    if(0 <= ny && ny < H && 0 <= nx && nx < W &&
	       lose(cur[r][i][j], cur[r][ny][nx])) safe = false;
	  }
	  cur[1 - r][i][j] = safe ? cur[r][i][j] : chg(cur[r][i][j]);
	}
      }
    }
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
	cout << cur[N % 2][i][j];
      }
      cout << endl;
    }
    if(t != T - 1) cout << endl;
  }
  return 0;
}
