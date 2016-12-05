// Time-stamp: <Tue Nov 29 23:45:14 東京 (標準時) 2016>
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

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main(int argc, char **argv){
  int f[5][5];
  for(int i = 0; i < 25; i++) cin >> f[i / 5][i % 5];
  int prev[25];
  FILL(prev, -1);

  queue<int> Q;
  Q.push(0);
  prev[0] = 0;
  while(!Q.empty()){
    int y = Q.front() / 5, x = Q.front() % 5;
    Q.pop();
    if(y == 4 && x == 4) break;
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(0 <= ny && ny < 5 && 0 <= nx && nx < 5 
	 && f[ny][nx] == 0 && prev[ny * 5 + nx] == -1){
	prev[ny * 5 + nx] = y * 5 + x;
	Q.push(ny * 5 + nx);
      }
    }
  }
  
  vector<int> path;
  int node = 24;
  while(node != prev[node]){
    path.push_back(node);
    node = prev[node];
  }
  path.push_back(0);
  reverse(ALL(path));
  for(int i = 0; i < path.size(); i++)
    cout << "(" << path[i] / 5 << ", " << path[i] % 5 << ")" << endl;
  return 0;
}
