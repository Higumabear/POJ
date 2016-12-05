// Time-stamp: <Sun Dec 04 18:26:48 東京 (標準時) 2016>
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

int dx[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[10] = {0, -1, -1, -1, 0, 0, 0, 1, 1, 1};
//南西、南、南東、西、０、東、北西、北、北東
int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  while(N--){
    char c;
    int prevx = 0, prevy = 0;
    ll area = 0;
    while(scanf("%c", &c) && c != '5'){
      ll curx = prevx + dx[c - '0'];
      ll cury = prevy + dy[c - '0'];
      area += (prevx * cury - prevy * curx);
      prevx = curx;
      prevy = cury;
    }
    if(area < 0) area *= -1;
    if(area % 2 == 0)
      printf("%lld\n", area / 2);
    else
      printf("%lld.5\n", area / 2);
  }
  return 0;
}
