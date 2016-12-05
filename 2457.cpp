// Time-stamp: <Wed Sep 14 00:18:32 東京 (標準時) 2016>
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
  int N, K;
  cin >> N >> K;

  vector<int> prev(K + 1, -1);
  vector<vector<int> > G;
  G.resize(K + 1);
  prev[1] = 0;
  for(int i = 0; i < N; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
  }
  
  queue<int> Q;
  Q.push(1);
  while(!Q.empty()){
    int c = Q.front(); Q.pop();
    if(c == K) break;
    for(int i = 0; i < G[c].size(); i++){
      if(prev[G[c][i]] == -1){
	Q.push(G[c][i]);
	prev[G[c][i]] = c;
      }
    }
  }
  if(prev[K] == -1) cout << -1 << endl;
  else{
    vector<int> p;
    while(K != 0){
      p.push_back(K);
      K = prev[K];
    }
    reverse(ALL(p));
    cout << p.size() << endl;
    for(int i = 0; i < p.size(); i++)
      cout << p[i] << endl;
  }
  return 0;
}
