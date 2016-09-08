#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdio>
#include <algorithm>

using namespace std;

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

int deg[20001];

int main(int argc, char **argv){

  int idx = 1;
  while(1){
    int a, b;
    set<int> node;
    UnionFind uf;
    fill(deg, deg + 20000, 0);
    
    while(scanf("%d %d", &a, &b), a + b){
      if(a <= -1 && b <= -1) goto L1;
      deg[b]++;
      node.insert(a);
      node.insert(b);
      uf.unite(a, b);
    }

    int root = 0;
    bool tree = true;
    for(set<int>::iterator it = node.begin();
	it != node.end(); it++){
      int c = *it;
      if(deg[c] >= 2) tree = false;
      if(!uf.same(*(node.begin()), c)) tree = false;
      if(deg[c] == 0) root++;
    }
    if(root != 1 && !node.empty()) tree = false;

    printf("Case %d is %s\n", idx++, tree ? "a tree." : "not a tree.");
  }
 L1:;
  return 0;
}
