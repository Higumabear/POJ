// Time-stamp: <Sat Oct 29 02:53:21 東京 (標準時) 2016>
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
  int N, Z, M;
  cin >> N >> Z >> M;
  N--, Z--;
  
  bool obstacle[1001];
  FILL(obstacle, false);
  for(int i = 0; i < M; i++){
    int t; cin >> t;
    obstacle[--t] = true;
  }
  for(int K = 1; ; K++){
    int cur = 0;
    bool vis[1001];
    FILL(vis, false);
    while(1){
      if(obstacle[cur]) break;
      if(vis[cur]) break;
      vis[cur] = true;
      if(cur == Z){
	cout << K << endl;
	return 0;
      }
      cur = (cur + K) % (N + 1);
    }
  }
  return 0;
}