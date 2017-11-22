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

int V;
map<int, pair<int, int> > p;
double d[300][300];

double ti(pair<int, int> &p, pair<int, int> &q, double h){
  return 60.0 * sqrt(pow(p.first - q.first, 2.0) +
		     pow(p.second - q.second, 2.0)) / h / 1000.0;
}

int main(){
  V = 0;
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  p[V++] = make_pair(sx, sy);
  p[V++] = make_pair(gx, gy);

  FILL(d, 1e100);
  
  while(1){
    if(cin.eof()) break;
    int x, y;
    cin >> x >> y;
    p[V++] = make_pair(x, y);
    while(cin >> x >> y, x != -1){
      p[V] = make_pair(x, y);
      d[V-1][V] = d[V][V-1] = ti(p[V-1], p[V], 40.0);
      V++;
    }
  }
  for(int i = 0; i < V; i++){
    d[i][i] = 0.0;
    for(int j = i + 1; j < V; j++)
      d[i][j] = d[j][i] = min(d[i][j], ti(p[i], p[j], 10.0));
  }
  for(int k = 0; k < V; k++)
    for(int i = 0; i < V; i++)
      for(int j = 0; j < V; j++)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  cout << (int)(d[0][1] + 0.5) << endl;
  return 0;
}
