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

int d[10001];

inline bool check(int v, int n){
  int a = 0;
  for(int i = 0; i < n; i++){
    a += d[i];
    if(a > v) return false;
    if(a == v) a = 0;
  }
  return true;
}

vector<int> div(int x){
  vector<int> ret;
  for(int i = 1; i * i <= x; i++){
    if(x % i == 0){
      ret.push_back(i);
      if(i * i != x) ret.push_back(x / i);
    }
  }
  sort(ALL(ret));
  return ret;
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int a, n;
    scanf("%d %d", &a, &n);

    int sum = 0, maxv = 0;
    for(int i = 0; i < n; i++){
      scanf("%d", d + i);
      sum += d[i];
      maxv = max(maxv, d[i]);
    }

    vector<int> f = div(sum);
    for(int i = 0; i < f.size(); i++){
      if(f[i] < maxv) continue;
      if(check(f[i], n)){
	printf("%d %d\n", a, f[i]);
	break;
      }
    }
  }
  return 0;
}
