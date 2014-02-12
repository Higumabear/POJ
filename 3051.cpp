#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

char p[1000][80];
int W, H;
int cnt;

int vx[4] = {-1, 0, 1, 0};
int vy[4] = {0, 1, 0, -1};

int dfs(int x, int y){
  int nx, ny;
  int res = 1;
  p[y][x] = '.';
  for(int i = 0; i < 4; i++){
    nx = vx[i] + x;
    ny = vy[i] + y;
    if(0 <= nx && nx < W && 0 <= ny && ny < H &&
       p[ny][nx] == '*'){
      res += dfs(nx, ny);
    }
  }
  return res;
}

int main(int argc, char **argv){
  scanf("%d %d", &W, &H);
  for(int i = 0; i < H; i++) scanf("%s", p[i]);
  
  int ans = 0;

  for(int j = 0; j < H; j++){
    for(int i = 0; i < W; i++)
      if(p[j][i] == '*')
	ans = max(ans, dfs(i, j));
    }
  printf("%d\n", ans);
  return 0;
}