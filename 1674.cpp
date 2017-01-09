// Time-stamp: <Sun Jan 08 15:06:29 東京 (標準時) 2017>
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

int in[10000], pos[10000];
int main(int argc, char **argv){
  int t; scanf("%d", &t);
  while(t--){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", in + i);
      in[i]--;
      pos[in[i]] = i;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
      if(in[i] == i) continue;
      int t = in[i], p = pos[i];
      swap(in[i], in[p]);
      pos[i] = i;
      pos[t] = p;
      cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}