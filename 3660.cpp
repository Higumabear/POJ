// Time-stamp: <Mon Aug 15 21:01:30 東京 (標準時) 2016>
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
  int N, M;
  scanf("%d %d", &N, &M);
  
  vector<vector<bool> > E(N, vector<bool>(N, false));
  for(int i = 0; i < M; i++){
    int s, t;
    scanf("%d %d", &s, &t);
    E[t - 1][s - 1] = true;
  }
  for(int i = 0; i < N; i++) E[i][i] = true;
  
  for(int k = 0; k < N; k++)
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	E[i][j] = E[i][j] | (E[i][k] && E[k][j]);

  int ans = 0;
  for(int i = 0; i < N; i++){
    int cnt = 0;
    for(int j = 0; j < N; j++)
      if(i != j) cnt += (E[i][j] ^ E[j][i]);
    ans += (cnt == N - 1);
  }
  cout << ans << endl;
  return 0;
}
