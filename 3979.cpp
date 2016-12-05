// Time-stamp: <Tue Nov 01 21:40:00 東京 (標準時) 2016>
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
  string s;
  while(cin >> s){
    int a, b, x, y;
    char op;
    sscanf(s.c_str(), "%d/%d%c%d/%d", &a, &b, &op, &x, &y);
    int l = b * y / gcd(b, y);
    a *= (l / b);
    x *= (l / y);

    int n = op == '+' ? a + x : a - x;
    int d = l;
    int g = gcd(abs(n), d);
    n /= g;
    d /= g;
    if(n == 0) printf("0\n");
    else if(n % d == 0) printf("%d\n", n / d);
    else printf("%d/%d\n", n, d);
  }
  return 0;
}
