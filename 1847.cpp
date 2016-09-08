// Time-stamp: <Sun Aug 07 12:45:42 東京 (標準時) 2016>
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
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int d[101][101];

int main(int argc, char **argv){
  int N, s, t;
  cin >> N >> s >> t;
  Fill(d, INF);
  
  for(int i = 0; i < N; i++){
    int k;
    cin >> k;
    for(int j = 0; j < k; j++){
      int a; cin >> a;
      d[i + 1][a] = (j == 0 ? 0 : 1);
    }
    d[i + 1][i + 1] = 0;
  }
  for(int k = 0; k < N + 1; k++)
    for(int i = 0; i < N + 1; i++)
      for(int j = 0; j < N + 1; j++)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  cout << (d[s][t] == INF ? -1 : d[s][t]) << endl;
  return 0;
}