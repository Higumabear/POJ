#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);

class UnionFind{
public:
  UnionFind(){
    for(int i = 0; i < 10000; i++)
      par[i] = i, rank[i] = 0;
  }
  UnionFind(int n){
    for(int i = 0; i < n; i++)
      par[i] = i, rank[i] = 0;
  }
  
  bool same(int x, int y){ return find(x) == find(y); }

  void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]){
      par[x] = y;
    }else{
      par[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }
  
private:
  int par[10000], rank[10000];
  int find(int x){
    return par[x] == x ? x : par[x] = find(par[x]);
  }
};


bool repaired[1010];
int x[1010], y[1010];
int main(int argc, char **argv){
  int N, D;
  scanf("%d %d\n", &N, &D);
  for(int i = 0; i < N; i++)
    scanf("%d %d\n", &x[i], &y[i]);

  UnionFind uf(1010);  
  FILL(repaired, false);

  char c;
  int p, q;
  while(1){
    while(1){
      c = getchar();
      if(c == 'O' || c == 'S' || c == EOF) break;
    }
    if(c == EOF) break;
    if(c == 'O'){
      scanf("%d", &p);
      p--;
      repaired[p] = true;
      for(int i = 0; i < N; i++){
	if(!repaired[i]) continue;
	double d = sqrt((y[i] - y[p]) * (y[i] - y[p]) +
			(x[i] - x[p]) * (x[i] - x[p]));
	if(d <= D)
	  uf.unite(i, p);
      }
    }else{
      scanf("%d %d", &p, &q);
      p--, q--;
      if(repaired[p] && repaired[q]
	 && uf.same(p, q)) cout << "SUCCESS" << endl;
      else cout << "FAIL" << endl;
    }
  }
}
