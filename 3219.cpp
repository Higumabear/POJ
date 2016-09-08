// Time-stamp: <Fri Dec 12 00:30:05 東京 (標準時) 2014>
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
bool isodd(int n, int k){
  if(n <= 1) return true;
  if(n % 2 == 0 && k % 2 == 1) return false;
  else return isodd(n / 2, k / 2);
}
int main(int argc, char **argv){
  int n, k;
  while(cin >> n >> k) cout << (isodd(n, k) ? 1 : 0) << endl;
  return 0;
}