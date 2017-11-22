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

pair<int, int> f[10001]; 

int main(){
  int c;
  scanf("%d", &c);
  while(c--){
    int n;
    double ax = 0, ay = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      pair<int, int> t;
      scanf("%d %d", &t.first, &t.second);
      ax += t.first, ay += t.second;
      f[i] = t;
    }
    ax /= n; ay /= n;
    sort(f, f + n);
    // dump(ax);
    // dump(ay);
    
    for(int i = 0; i < n; i++){
      ll p = floor(2.0 * ax - f[i].first + EPS);
      ll q = floor(2.0 * ay - f[i].second + EPS);
      if(!binary_search(f, f + n, make_pair((int)p, (int)q))){
	puts("no");
	goto L1;
      }
    }
    puts("yes");
  L1:;
  }
  return 0;
}
