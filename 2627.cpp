// Time-stamp: <Tue Mar 28 22:50:21 東京 (標準時) 2017>
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

double x[1010], y[1010];
bool E[1010][1010];

int main(int argc, char **argv){
  double v, m;
  cin >> v >> m;

  int N = 0;
  while(cin >> x[N] >> y[N]) N++;
  
  FILL(E, false);
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      double L = sqrt((x[i] - x[j]) * (x[i] - x[j]) + 
		      (y[i] - y[j]) * (y[i] - y[j]));
      double t = L / v / 60.0;
      if(t < m) E[i][j] = E[j][i] = true;
    }
  }
  
  vector<int> dist(N, -1);
  queue<int> Q;
  Q.push(0);
  dist[0] = 0;
  while(!Q.empty()){
    int idx = Q.front(); Q.pop();
    if(idx == 1) break;
    for(int i = 0; i < N; i++){
      if(E[idx][i] && dist[i] == -1){
	dist[i] = dist[idx] + 1;
	Q.push(i);
      }
    }
  }
  if(dist[1] == -1) cout << "No." << endl;
  else cout << "Yes, visiting " << dist[1] - 1 << " other holes." << endl;
  return 0;
}
