// Time-stamp: <Thu Feb 02 23:42:16 東京 (標準時) 2017>
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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
string dir("SENW");

double fy[3], fx[3], ty[3], tx[3];

bool reach(double ay, double ax, double by, double bx){
  for(int i = 0; i < 3; i++){
    double ta = (fx[i] - tx[i]) * (ay - fy[i]) + (fy[i] - ty[i]) * (fx[i] - ax);
    double tb = (fx[i] - tx[i]) * (by - fy[i]) + (fy[i] - ty[i]) * (fx[i] - bx);
    double tc = (ax - bx) * (fy[i] - ay) + (ay - by) * (ax - fx[i]);
    double td = (ax - bx) * (ty[i] - ay) + (ay - by) * (ax - tx[i]);
    if(tc * td < 0 && ta * tb < 0) return false;
  }
  return true;
}

int main(int argc, char **argv){
  int x, y, gx, gy;
  while(cin >> x >> y){
    if(x == 0 && y == 0) break;
    cin >> gx >> gy;
    x--, y--, gx--, gy--;

    for(int i =0 ; i < 3; i++){
      cin >> fx[i] >> fy[i] >> tx[i] >> ty[i];
      fx[i] -= 0.5, fy[i] -= 0.5, tx[i] -= 0.5, ty[i] -= 0.5;
    }

    pair<int, int> init(y, x);
    queue<pair<int, int> > Q;
    Q.push(init);
    map<pair<int, int>, int> prev;
    prev[init] = -1;
    while(!Q.empty()){
      pair<int, int> q = Q.front(); Q.pop();
      int cy = q.first, cx = q.second;
      if(gy == cy && gx == cx) break;
      for(int i = 0; i < 4; i++){
	int ny = cy + dy[i], nx = cx + dx[i];
	pair<int, int> next = make_pair(ny, nx);
	if(0 <= ny && ny < 6 && 0 <= nx && nx < 6 && 
	   !prev.count(next) && reach(cy, cx, ny, nx)){
	  prev[next] = i;
	  Q.push(next);
	}
      }
    }
    string ans;
    pair<int, int> pos = make_pair(gy, gx);
    int d = prev[pos];
    while(d != -1){
      ans += dir[d];
      pos.first += dy[(d + 2) % 4];
      pos.second += dx[(d + 2) % 4];
      d = prev[pos];
    }
    reverse(ALL(ans));
    cout << ans << endl;
  }
  
  return 0;
}
