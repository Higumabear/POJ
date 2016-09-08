// Time-stamp: <Sun Aug 07 00:09:55 東京 (標準時) 2016>
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

using namespace std;

int dx[] = {0, 1, 0, -1, 0, 0};
int dy[] = {1, 0, -1, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
char f[31][31][31];
int c[31][31][31];
struct pt{
  int z, y, x;
  pt(int z, int y, int x) : z(z), y(y), x(x) {};
};

int main(int argc, char **argv){
  int L, R, C;
  while(cin >> L >> R >> C, L){
    memset(f, '.', sizeof(f));
    memset(c, -1, sizeof(c));
    int z, y, x;
    for(int i = 0; i < L; i++){
      string s;
      for(int j = 0; j < R; j++){
	cin >> s;
	for(int k = 0; k < C; k++){
	  if(s[k] == 'S') z = i, y = j, x = k;
	  f[i][j][k] = s[k];
	}
      }
    }
    //cout << z << y << x << endl;
    queue<pt> Q;
    Q.push(pt(z, y, x));
    c[z][y][x] = 0;
    while(!Q.empty()){
      pt t = Q.front();
      Q.pop();
      if(f[t.z][t.y][t.x] == 'E'){
	cout << "Escaped in " << c[t.z][t.y][t.x] << " minute(s)." << endl;
	goto L1;
      }
      
      for(int i = 0; i < 6; i++){
	int nz = t.z + dz[i], ny = t.y + dy[i], nx = t.x + dx[i];
	if(0 <= nz && nz < L && 0 <= ny && ny < R && 0 <= nx && nx < C && 
	   f[nz][ny][nx] != '#' && c[nz][ny][nx] == -1){
	  Q.push(pt(nz, ny, nx));
	  c[nz][ny][nx] = c[t.z][t.y][t.x] + 1;
	}
      }
    }
    cout << "Trapped!" << endl;
  L1:;
  }
  return 0;
}
