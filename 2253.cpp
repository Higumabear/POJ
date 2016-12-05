// Time-stamp: <Mon Dec 05 23:21:34 東京 (標準時) 2016>
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

struct path{
  int from, to;
  double d;
  path(){}
  path(int from, int to, double d) : from(from), to(to), d(d) {}
  bool operator<(const path &r)const{
    return d < r.d;
  }
};

int main(int argc, char **argv){
  int N;
  int idx = 0;
  while(scanf("%d", &N), N){
    int x[200], y[200];
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
    
    vector<path> pa;
    for(int i = 0; i < N; i++)
      for(int j = i; j < N; j++)
	pa.push_back(path(i, j, sqrt((x[i] - x[j]) * (x[i] - x[j]) + 
				     (y[i] - y[j]) * (y[i] - y[j]))));
    sort(ALL(pa));
    
    double ub = 1e10, lb = 0.0;
    for(int i = 0; i < 100; i++){
      double mid = (ub + lb) * 0.5;
      bool d[200][200];
      FILL(d, false);
      for(int i = 0; i < pa.size(); i++)
	if(mid >= pa[i].d + EPS) 
	  d[pa[i].from][pa[i].to] = d[pa[i].to][pa[i].from] = true;
      
      queue<int> Q;
      Q.push(0);
      vector<bool> vis(N, false);
      vis[0] = true;
      bool reach = false;
      while(!Q.empty()){
	int p = Q.front(); Q.pop();
	if(p == 1){
	  reach = true;
	  break;
	}
	for(int i = 0; i < N; i++){
	  if(d[p][i] && !vis[i]){
	    Q.push(i);
	    vis[i] = true;
	  }
	}
      }
      if(reach) ub = mid;
      else lb = mid;
    }
    printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++idx, ub);
  }
  return 0;
}
