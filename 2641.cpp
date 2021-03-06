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

int main(){
  double a, b, s, n, m;
  while(cin >> a >> b >> s >> n >> m, a){
    double v = sqrt(a * a * n * n + b * b * m * m) / s;
    double ang = acos(b * m / v / s) * 180 / acos((double)-1);
    printf("%.2lf %.2lf\n", 90 - ang, v);      
  }
  return 0;
}
