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

//置換群の列挙 インデックスで返す O(nlogn)
template<typename T>
vector<vector<int> > perm_group(vector<T> src){
  vector<T> dst = src;
  sort(dst.begin(), dst.end());

  int N = src.size();
  map<T, int> src_index, dst_index;
  for(int i = 0; i < N; i++) 
    src_index[src[i]] = i, dst_index[dst[i]] = i;
  
  vector<bool> vis(N, false);
  vector<vector<int> > ret;
  for(int i = 0; i < N; i++){
    if(vis[i]) continue;
    int start = i, idx = i;
    vector<int> perm;
    perm.push_back(start);
    vis[start] = true;
    while(src_index[dst[idx]] != start){
      idx = src_index[dst[idx]];
      perm.push_back(idx);
      vis[idx] = true;
    }
    ret.push_back(perm);
  }
  return ret;
}

int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  vector<int> s(N);
  int min1 = INF;
  for(int i = 0; i < N; i++){
    scanf("%d", &s[i]);
    min1 = min(min1, s[i]);
  }
  
  vector<vector<int> > p = perm_group(s);

  int ans = 0;
  for(int i = 0; i < p.size(); i++){
    if(p[i].size() == 1) continue;

    int min2 = INF;
    int sum = 0;
    for(int j = 0; j < p[i].size(); j++){
      sum += s[p[i][j]];
      min2 = min(min2, s[p[i][j]]);
    }
    ans += min(sum - min2 + (p[i].size() - 1) * min2, 
	       sum + min2 + (p[i].size() + 1) * min1);
  }
  printf("%d\n", ans);
  return 0;
}
