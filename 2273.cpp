// Time-stamp: <Sun Sep 11 15:08:40 東京 (標準時) 2016>
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

int main(int argc, char **argv){
  string s;
  int r, c;
  char R, C;
  while(scanf("%c%d%c%d", &R, &r, &C, &c), r + c){
    int idx = 0;
    char alpha[20];
    getchar();
    while(c > 0){
      c--;
      alpha[idx++] = (c % 26) + 'A';
      c /= 26;
    }
    for(int i = idx - 1; i >= 0; i--)
      putchar(alpha[i]);
    printf("%d\n", r);
  }
  return 0;
}
