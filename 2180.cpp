#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

bool p[60][60][60];
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, -1, 0, 1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int surr(int x, int y, int z){
  int cnt = 0;
  for(int i = 0; i < 6; i++){
    int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
    if(nz < 0) continue;
    cnt += !p[nx][ny][nz];
  }
  return cnt;
}


int x[30000], y[30000], z[30000];

int main(int argc, char **argv){
  int N;
  int idx;
  char c;
  cin >> N;
  memset(p, false, sizeof(p));

  x[0] = 30, y[0] = 30, z[0] = 0;
  p[30][30][0] = true;
  for(int i = 0; i < N - 1; i++){
    cin >> idx >> c;
    int nx = x[idx - 1], ny = y[idx - 1], nz = z[idx - 1];
    //cout << nx << " " << ny << " " << nz << endl;
    switch(c){
    case 'L': nx--; break;
    case 'R': nx++; break;
    case 'F': ny++; break;
    case 'B': ny--; break;
    case 'O': nz++; break;
    default:  nz--;
    }
    //cout << nx << " " << ny << " " << nz << endl;
    if(p[nx][ny][nz]){
      cout << -1 << endl;
      return 0;
    }
    x[i + 1] = nx, y[i + 1] = ny, z[i + 1] = nz;
    p[nx][ny][nz] = true;
  }

  int ans = 0;
  for(int i = 0; i < N; i++)
    ans += surr(x[i], y[i], z[i]);
  cout << ans << endl;
  return 0;
}

