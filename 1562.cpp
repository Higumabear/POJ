#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(int argc, char **argv){
  int H, W; 
  while(cin >> H >> W, H | W){
    vector<string> f;
    string s;
    for(int i = 0; i < H; i++){
      cin >> s;
      f.push_back(s);
    }

    int cnt = 0;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
	if(f[i][j] != '@') continue;
	cnt++;
	queue<int> Q;
	Q.push(i * W + j);
	while(!Q.empty()){
	  int y = Q.front() / W, x = Q.front() % W;
	  Q.pop();
	  f[y][x] = '*';
	  for(int k = 0; k < 8; k++){
	    int nx = x + dx[k], ny = y + dy[k];
	    if(0 <= nx && nx < W && 0 <= ny && ny < H
	       && f[ny][nx] == '@') Q.push(ny * W + nx);
	  }
	}
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
