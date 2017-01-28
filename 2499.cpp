// Time-stamp: <Sun Jan 15 13:34:08 東京 (標準時) 2017>
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
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++){
    int a, b, l = 0, r = 0;
    scanf("%d %d", &a, &b);

    int idx = 0;
    while(a * b){
      if(idx++ % 2 == 0){
	l += a / b;
	a %= b;
	if(a == 0) l--;
      }else{
	r += b / a;
	b %= a;
	if(b == 0) r--;
      }
    }
    printf("Scenario #%d:\n", i);
    printf("%d %d\n\n", l, r);
  }
  return 0;
}
