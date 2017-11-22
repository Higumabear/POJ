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

struct r{
  int x[2], y[2];
};

bool contain(r &a, r &b){ // b contains a
  return b.x[0] <= a.x[0] && a.x[1] <= b.x[1] &&
    b.y[0] <= a.y[0] && a.y[1] <= b.y[1];
}

int main(){
  int n;
  while(~scanf("%d", &n)){
    vector<r> rec(n);
    for(int i = 0; i < n; i++){
      scanf("%d %d %d %d",
	    &rec[i].x[0], &rec[i].x[1],
	    &rec[i].y[0], &rec[i].y[1]);
    }
    vector<bool> in(n, false);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	if(i == j) continue;
	in[i] = in[i] | contain(rec[i], rec[j]);
      }
    }
    cout << count(ALL(in), true) << endl;
  }
  return 0;
}
