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

int d[10], p[10], v[10];
int N, D;

inline int check(){
  int Ap = 0, Bp = 0, Av = 0, Bv = 0;
  bool sw = true;
  for(int i = 0; i < N; i++){
    if(sw){
      Ap += p[d[i]], Av += v[d[i]];
      if(Ap - Bp > D) sw = false;
    }else{
      Bp += p[d[i]], Bv += v[d[i]];
      if(Bp - Ap > D) sw = true;
    }
  }
  return Bv;
}

int main(){
  for(int i = 0; i < 10; i++) d[i] = i;
  cin >> N >> D;
  for(int i = 0; i < N; i++) cin >> p[i] >> v[i];

  int ans = 0;
  do{
    ans = max(ans, check());
  }while(next_permutation(d, d + N));
  cout << ans << endl;
  return 0;
}
