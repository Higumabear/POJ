#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <math.h>
using namespace std;

char field[6][6];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

set<int> s;

void dfs(int x, int y, int jump, int num){
  int c = (int)(field[y][x] - '0');
  if(jump == 5){
    num += c;
    //cout << num << endl;
    s.insert(num);
    return;
  }

  int t = c * (int)pow((double)10, (double)(5 - jump));
  num += t;
  
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < 5 && 0 <= ny && ny < 5){
      dfs(nx, ny, jump + 1, num);
    }
  }
  return;
}

int main(int argc, char **argv){
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      cin >> field[i][j];
  
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++){
      dfs(j, i, 0, 0);
    }
  cout << (int)s.size() << endl;
  return 0;
}