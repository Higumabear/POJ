// Time-stamp: <Tue Jan 31 20:28:35 東京 (標準時) 2017>
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

int n, ans;
int m[7][7];

inline void check(const vector<int> &p){
  int v = -1;
  for(int j = 0; j < n; j++){
    int tmp = 0;
    for(int i = 0; i < n; i++)
      tmp += m[i][(j + p[i]) % n];
    if(tmp >= ans) return;
    v = max(tmp, v);
  }
  ans = min(ans, v);
  return;
}

inline bool check2(int idx, const vector<int> &p){
  for(int j = 0; j < n; j++){
    int tmp = 0;
    for(int i = 0; i < idx; i++)
      tmp += m[i][(j + p[i]) % n];
    if(tmp >= ans) return false;
  }
  return true;
}

void dfs(int idx, vector<int> &p){
  if(idx == n){
    check(p);
    return;
  }
  if(!check2(idx, p)) return;
  
  for(int i = 0; i < n; i++){
    p[idx] = i;
    dfs(idx + 1, p);
  }
  return;
}

int main(int argc, char **argv){
  while(scanf("%d", &n)){
    ans = INF;
    if(n == -1) break;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	scanf("%d", &m[i][j]);
    
    vector<int> tmp(n, 0);
    dfs(0, tmp);
    printf("%d\n", ans);
  }
  return 0;
}
