// Time-stamp: <Sun Dec 18 03:56:30 東京 (標準時) 2016>
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

class UnionFind{
public:
  UnionFind();
  UnionFind(int num){
    for(int i = 0; i < num; i++) parent[i] = i, rank[i] = 0;
  }

  bool same (int x, int y) { return find(x) == find(y); }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(rank[y] > rank[x]){
      parent[x] = y;
    }else{
      parent[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

private:
  int rank[200001], parent[200001];

  int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
  }
};

int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  while(T--){
    int N, M;
    scanf("%d%d", &N, &M);
    getchar();
    UnionFind uf(2 * N);
    for(int i = 0; i < M; i++){
      char c;
      int a, b;
      scanf("%c%d%d", &c, &a, &b);
      getchar();
      a--, b--;
      if(c == 'D'){
	uf.unite(a, b + N);
	uf.unite(a + N, b);
      }else{
	if(uf.same(a, b)) 
	  puts("In the same gang.");
	else if(uf.same(a, b + N) || uf.same(a + N, b))
	  puts("In different gangs.");
	else
	  puts("Not sure yet.");
      }
    }
  }
  return 0;
}
