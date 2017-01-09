// Time-stamp: <Thu Dec 08 00:15:41 東京 (標準時) 2016>
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

int dp[1010][16][16];
vector<pair<int, int> > p;
int rec(int idx, int w, int b){
  if(idx == p.size()){
    if(w == 15 && b == 15) return 0;
    else return -INF;
  }
  if(dp[idx][w][b] != -1) return dp[idx][w][b];
  
  int ret = -INF;
  ret = max(ret, rec(idx + 1, w, b));
  if(w < 15) ret = max(ret, rec(idx + 1, w + 1, b) + p[idx].first);
  if(b < 15) ret = max(ret, rec(idx + 1, w, b + 1) + p[idx].second);
  return dp[idx][w][b] = ret;
}

int main(int argc, char **argv){
  int a, b;
  while(cin >> a >> b)
    p.push_back(make_pair(a, b));
  stable_sort(p.rbegin(), p.rend());
  for(int i = 0; i < p.size(); i++){
    swap(p[i].first, p[i].second);
  }
  stable_sort(p.rbegin(), p.rend());
  // for(int i = 0; i < p.size(); i++){
  //   cout << p[i].first << " " << p[i].second << endl;
  // }

  FILL(dp, -1);
  cout << rec(0, 0, 0) << endl;
  return 0;
}
