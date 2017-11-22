// Time-stamp: <Sun Mar 12 22:11:33 東京 (標準時) 2017>
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

int main(int argc, char **argv){
  int N;
  cin >> N;
  vector<pair<int, int> > p(N);
  map<pair<int, int>, bool> e;
  for(int i = 0; i < N; i++){
    cin >> p[i].first >> p[i].second;
    e[p[i]] = true;
  }
  int cnt = 0;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      int sx = p[i].first, sy = p[i].second;
      int ex = p[j].first, ey = p[j].second;
      
      int x1 = sx - ey + sy, y1 = sy + ex - sx;
      int x2 = ex - ey + sy, y2 = ey + ex - sx;
      if(e.count(make_pair(x1, y1)) && e.count(make_pair(x2, y2)))
	cnt++;
      x1 = sx + ey - sy, y1 = sy - ex + sx;
      x2 = ex + ey - sy, y2 = ey - ex + sx;
      if(e.count(make_pair(x1, y1)) && e.count(make_pair(x2, y2)))
	cnt++;
    }
  }
  cout << cnt / 4 << endl;
  return 0;
}
