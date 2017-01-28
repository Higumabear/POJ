// Time-stamp: <Thu Jan 19 21:55:46 東京 (標準時) 2017>
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

double comb(int a, int b){
  double ret = 1.0;
  for(int i = 0; i < b; i++)
    ret = ret * (a - i) / (b - i);
  return ret;
}
int main(int argc, char **argv){
  int n, m;
  while(scanf("%d %d", &n, &m)){
    if(n == -1 && m == -1) break;
    printf("%d-%d split: %.8lf\n", n, m,
	   (n != m ? 2 : 1) * comb(13, n) * comb(13, m) / comb(26, n + m));
  }
  return 0;
}
