// Time-stamp: <Sat Dec 17 02:12:36 東京 (標準時) 2016>
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

int n;
int v[10000];
bool anti(){
  for(int a = 0; a < n; a++){
    for(int d = 1; a + 2 * d < n; d++){
      if(v[a] < v[a + d] && v[a + d] < v[a + 2 * d]) return false;
      if(v[a] > v[a + d] && v[a + d] > v[a + 2 * d]) return false;
    }
  }
  return true;
}
int main(int argc, char **argv){
  while(scanf("%d:", &n), n){
    for(int i = 0; i < n; i++){
      int t;
      scanf("%d", &t);
      v[t] = i;
    }
    printf("%s\n", anti() ? "yes" : "no");
  }
  return 0;
}
