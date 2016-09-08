// Time-stamp: <Sun Aug 07 18:03:03 東京 (標準時) 2016>
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

int main(int argc, char **argv){
  int N;
  scanf("%d", &N);

  int win = 0, ans;
  for(int i = 0; i < N; i++){
    int cnt = 0;
    for(int j = 0; j < N; j++){
      int c;
      scanf("%d", &c);
      cnt += c == 3;
    }
    if(win < cnt){
      win = cnt;
      ans = i + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
