// Time-stamp: <Fri Feb 17 01:32:37 東京 (標準時) 2017>
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
  int cnt = 1;
  while(cin >> N){
    vector<vector<int> > f(21, vector<int>(21, INF));
    int to;
    for(int i = 0; i < N; i++){
      cin >> to;
      f[1][to] = f[to][1] = 1;
    }
    for(int i = 2; i < 20; i++){
      cin >> N;
      for(int j = 0; j < N; j++){
	cin >> to;
	f[i][to] = f[to][i] = 1;
      }
    }
    for(int k = 0; k < 21; k++) f[k][k] = 0;
    for(int k = 0; k < 21; k++)
      for(int i = 0; i < 21; i++)
	for(int j = 0; j < 21; j++)
	  f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    int T;
    cin >> T;
    cout << "Test Set #" << cnt++ << endl;
    for(int i = 0; i < T; i++){
      int s, t;
      cin >> s >> t;
      cout << s << " to " << t << ": " << f[s][t] << endl;
    }
    cout << endl;
  }
  return 0;
}
