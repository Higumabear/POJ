// Time-stamp: <Wed Jun 08 00:04:58 東京 (標準時) 2016>
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

int t9(int a){
  int base = 1;
  int ret = 0;
  while(a){
    ret += base * (a % 10);
    if(a % 10 > 4) ret -= base;
    base = base * 9;
    a /= 10;
  }
  return ret;
}

int main(int argc, char **argv){
  int n;
  while(cin >> n, n)
    cout << n << ": " << t9(n) << endl;
  return 0;
}
