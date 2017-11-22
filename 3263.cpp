// Time-stamp: <Mon May 08 22:04:12 東京 (標準時) 2017>
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

int cum[10010];

int main(int argc, char **argv){
  int N, I, H, R;
  scanf("%d %d %d %d", &N, &I, &H, &R);

  set<pair<int, int> > p;
  for(int i = 0; i < R; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    int l = min(a, b), r = max(a, b);
    if(!p.insert(make_pair(l, r)).second) continue;
    cum[l + 1]++;
    cum[r]--;
  }
  for(int i = 1; i <= N; i++){
    cum[i] += cum[i - 1];
    printf("%d\n", H - cum[i]);
  }

  return 0;
}
