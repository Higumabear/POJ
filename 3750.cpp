// Time-stamp: <Sun Dec 11 23:43:13 東京 (標準時) 2016>
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

int N, W, S;
bool vis[70];
vector<string> nam;
int nextidx(int idx){
  int i = 1;
  for(; i < N; i++)
    if(!vis[(idx + i) % N]) break;
  return (idx + i) % N;
}

int main(int argc, char **argv){
  cin >> N;
  nam.resize(N);
  for(int i = 0; i < N; i++) cin >> nam[i];
  char c;
  cin >> W >> c >> S;
  FILL(vis, false);
  
  int idx = (W - 2 + N) % N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < S; j++){
      idx = nextidx(idx);
    }
    vis[idx] = true;
    cout << nam[idx] << endl;
  }
  return 0;
}
