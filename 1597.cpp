// Time-stamp: <Thu Aug 04 22:27:50 東京 (標準時) 2016>
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

using namespace std;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
int main(int argc, char **argv){
  int x, y;
  while(scanf("%d %d", &x, &y) != -1)
    printf("%10d%10d    %s Choice\n\n", 
	   x, y, (gcd(x, y) == 1 ? "Good" : "Bad"));
  return 0;
}
