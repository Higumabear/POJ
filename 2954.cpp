// Time-stamp: <Sun Nov 27 22:57:45 東京 (標準時) 2016>
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

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }

int main(int argc, char **argv){
  int x1, y1, x2, y2, x3, y3;
  while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
    if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 & y3 == 0) break;

    int b = gcd(abs(x1 - x2), abs(y1 - y2)) + gcd(abs(x2 - x3), abs(y2 - y3)) + gcd(abs(x3 - x1), abs(y3 - y1));
    int S2 = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    cout << (S2 + 2 - b) / 2 << endl;
  }
  return 0;
}
