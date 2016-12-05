// Time-stamp: <Wed Oct 05 22:02:08 東京 (標準時) 2016>
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

int vis[1000000];
inline int trim(int a){
  return (a % 100000) / 10;
}

int main(int argc, char **argv){
  FILL(vis, -1);
  int a, v;
  int times = 0;
  cin >> a;
  while(1){
    v = trim(a);
    a = (v * v) % 1000000;
    if(vis[a] >= 0) break;
    vis[a] = times++;
    //cout << a << endl;
  }
  cout << a << " " << times - vis[a] << " " << times + 1 << endl;
  return 0;
}