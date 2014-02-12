#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
//const int MAX_N = ;

int N, M;
char a[100][100];

void dfs(int x, int y){
  a[x][y] = '.';
  for(int dx = -1; dx <= 1; dx++){
    for(int dy = -1; dy <= 1; dy++){
      int nx = x + dx, ny = y + dy;
      if(0 <= nx && nx < N && 0 <= ny && ny < M && a[nx][ny] == 'W'){
        dfs(nx, ny);
      }
    }
  }
  return ;
}

int main()
{
  int res = 0;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(a[i][j] == 'W'){
        dfs(i, j);
        res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}