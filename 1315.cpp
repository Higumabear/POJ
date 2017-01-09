// Time-stamp: <Sat Jan 07 13:13:27 東京 (標準時) 2017>
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

int T;
int ans;
char f[5][5];

void check(){
  int num = 0;
  for(int i = 0; i < T; i++){
    for(int j = 0; j < T; j++){
      if(f[i][j] != '*') continue;
      int cnt = 0;
      for(int k = 0; k < T; k++){
	if(f[k][j] == 'X') cnt = 0;
	if(f[k][j] == '*') cnt++;
	if(cnt == 2) return;
      }
      cnt = 0;
      for(int k = 0; k < T; k++){
	if(f[i][k] == 'X') cnt = 0;
	if(f[i][k] == '*') cnt++;
	if(cnt == 2) return;
      }
      num++;
    }
  }
  ans = max(ans, num);
}
void rec(int y, int x){
  if(y == T){
    check();
    return;
  }
  if(f[y][x] == '.'){
    f[y][x] = '*';
    rec((x + 1) % T ? y : y + 1, (x + 1) % T);
    f[y][x] = '.';
  }
  rec((x + 1) % T ? y : y + 1, (x + 1) % T);
  return;
}
int main(int argc, char **argv){
  while(cin >> T, T){
    for(int i = 0; i < T; i++)
      for(int j = 0; j < T; j++) cin >> f[i][j];
    ans = 0;
    rec(0, 0);
    cout << ans << endl;
  }
  return 0;
}
