// Time-stamp: <Tue Apr 25 01:36:43 東京 (標準時) 2017>
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

int n;
int s[20001];
int *sa, *lcp;

int *suffix_array(int *str) {
  int *v, *u, *g, *b, r[256];
  v = new int[n+1]; u = new int[n+1]; g = new int[n+1]; b = new int[n+1];
  for(int i = 0; i <= n; i++) {
    v[i] = i;
    g[i] = str[i];
  }
  for(int h = 1; ; h *= 2) {
    int m = *max_element(g, g+n+1);
    for(int k = h; k >= 0; k -= h) {
      for(int ord = 0; m >> ord; ord += 8) {
	memset(r, 0, sizeof(r));
	for(int i = 0; i <= n; i++)
	  r[(g[min(v[i]+k, n)] >> ord) & 0xff]++;
	for(int i = 1; i < 256; i++)
	  r[i] += r[i-1];
	for(int i = n; i >= 0; i--)
	  u[ --r[(g[min(v[i]+k, n)] >> ord) & 0xff] ] = v[i];
	swap(u, v);
      }
    }
    b[0] = 0;
    for(int i = 1; i <= n; i++)
      b[i] = b[i-1] + ((g[v[i-1]] != g[v[i]] ? g[v[i-1]] < g[v[i]] : g[v[i-1]+h] < g[v[i]+h]) ? 1 : 0);
    if (b[n] == n)
      break;
    for(int i = 0; i <= n; i++)
      g[v[i]] = b[i];
  }
  delete[] g; delete[] b; delete[] u;
  return v;
}

int* height_array(int *text, int *sa, int n) {
  int* height = new int[n];
  int* rank = new int[n];
  for(int i = 0; i < n; i++)
    rank[sa[i]] = i;
  int h = 0;
  height[0] = 0;
  for(int i = 0; i < n; i++) {
     if (rank[i] > 0) {
      int k = sa[rank[i]-1];
      while(text[i+h] == text[k+h])
	h++;
      height[rank[i]] = h;
      if (h > 0)
	h--;
    }
  }
  delete[] rank;
  return height;
}

bool solve(int x){
  int ma, mi;
  ma = mi = sa[1];
  for(int i = 2; i <= n; i++){
    if(lcp[i] >= x && i <= n){
      mi = min(mi, sa[i]);
      ma = max(ma, sa[i]);
      if(ma - mi >= x) return true;
      continue;
    }
    ma = mi = sa[i];
  }
  return false;
}

int main(int argc, char **argv){
  while(scanf("%d", &n), n){
    // for(int i = 0; i < n; i++) scanf("%d", s + i);
    // for(int i = n - 1; i >= 1; i--) 
    //   s[i] = s[i] - s[i - 1] + 100;
    // s[0] = 0;

    int r, e;
    scanf ("%d", &r);
    for (int i=1; i<n; i++){
      scanf ("%d", &e);
      s[i-1] = r - e + 100;
      r = e;
    }
    s[--n] = 0;

    sa = new int[n + 1];
    lcp = new int[n + 1];

    sa = suffix_array(s);
    lcp = height_array(s, sa, n);

    int lb = 1, ub = n / 2;
    int ans = 0;
    while(lb <= ub){
      int mid = (ub + lb) / 2;
      if(solve(mid)){
	ans = mid;
	lb = mid + 1;
      }else
	ub = mid - 1;
    }
    printf("%d\n", ans < 4 ? 0 : ans + 1);
  }
  return 0;
}
