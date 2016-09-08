// Time-stamp: <Wed May 18 10:42:43 東京 (標準時) 2016>
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

using namespace std;

int uf[30001];
int find(int x){
  return uf[x] == x ? x : uf[x] = find(uf[x]);
}
int unite(int a, int b){
  return uf[find(a)] = uf[find(b)] = find(a);
}
//bool suspect[30001];

int main(int argc, char **argv){
  int n, m;
  while(cin >> n >> m, n + m){
    for(int i = 0; i < n; i++) uf[i] = i;
    for(int i = 0; i < m; i++){
      int k; cin >> k;
      int a; cin >> a;
      for(int j = 0; j < k - 1; j++){
	int b; cin >> b;
	if(find(a) != find(b))
	  unite(a, b);
      }
    }
    int cnt = 0;
    for(int i = 1; i < n; i++)
      if(find(0) == find(i)) cnt++;
    cout << cnt + 1 << endl;
  }
  return 0;
}
