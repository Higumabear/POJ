#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

char f[20][20];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int step;
int W, H;

void dfs(int x, int y){
  f[y][x] = '#';
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < W && 0 <= ny && ny < H && f[ny][nx] == '.'){
      step++;
      dfs(nx, ny);
    }
  }
}

int main(){
  while(cin >> W >> H){
    if(W == 0 && H == 0) break;
    step = 1;
    int sx, sy;

    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++){
	char c;
	cin >> c;
	if(c == '@'){
	  sx = j;
	  sy = i;
	}
	f[i][j] = c;
      }
    dfs(sx, sy);
    cout << step << endl;
  }
  return 0;
}