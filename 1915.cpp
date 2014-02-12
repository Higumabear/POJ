#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(){
  int n; cin >> n;
  while(n--){
    int l, sx, sy, gx, gy;
    cin >> l;
    cin >> sx >> sy;
    cin >> gx >> gy;
    queue<pair<int, int> > Q;
    vector<int> dist(l * l, 1 << 29);
    dist[sy * l + sx] = 0;
    Q.push(make_pair(sy, sx));
    while(!Q.empty()){
      int y = Q.front().first;
      int x = Q.front().second;
      Q.pop();
      if(x == gx && y == gy){
	cout << dist[y * l + x] << endl;
	break;
      }
      for(int i = 0; i < 8; i++){
	int ny = y + dy[i];
	int nx = x + dx[i];
	if(0 <= nx && nx < l && 0 <= ny && ny < l 
	   && dist[ny * l + nx] > dist[y * l + x] + 1){
	  dist[ny * l + nx] = dist[y * l + x] + 1;
	  Q.push(make_pair(ny, nx));
	}
      }
    }
  }
}