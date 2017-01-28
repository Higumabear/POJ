// Time-stamp: <Wed Jan 18 22:40:43 東京 (標準時) 2017>
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

ll r[10001];
int main(int argc, char **argv){
  int t;
  scanf("%d", &t);
  while(t--){
    int N, F;
    scanf("%d %d", &N, &F);
    for(int i = 0; i < N; i++) scanf("%lld", r + i);
    
    double lb = 0.0, ub = 1e10;
    for(int i = 0; i < 200; i++){
      double mid = (lb + ub) / 2;
      
      int cnt = 0;
      for(int j = 0; j < N; j++) 
	cnt += floor((r[j] * r[j] * 3.141592653589793) / mid);
      if(cnt >= F + 1) lb = mid;
      else ub = mid;
    }
    printf("%.4lf\n", ub);
  }
  return 0;
}
