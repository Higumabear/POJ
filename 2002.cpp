// Time-stamp: <Mon Feb 20 01:03:19 東京 (標準時) 2017>
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


pair<int, int> p[1010];

int main(int argc, char **argv){
  int T;
  while(scanf("%d", &T), T){
    set<pair<int, int> > a;
    for(int i = 0; i < T; i++){
      scanf("%d %d", &p[i].first, &p[i].second);
      a.insert(p[i]);
    }
    sort(p, p + T);
    
    int cnt = 0;
    for(int i = 0; i < T; i++){
      for(int j = i + 1; j < T; j++){
	int tx = p[i].first, ty = p[i].second;
	int ux = p[j].first, uy = p[j].second;
      
	int x1 = -ty + uy + ux, y1 = tx - ux + uy;
	int x2 = -ty + uy + tx, y2 = tx - ux + ty;
	if(a.find(make_pair(x1, y1)) != a.end() && 
	   a.find(make_pair(x2, y2)) != a.end()) cnt++;
      }
    }
    printf("%d\n", cnt / 2);
  }
  return 0;
}
