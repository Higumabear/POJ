/*
  Strongly connected components decomposition (Kosaraju)
  
  Complexity:
  O(V + E)

  Verified:
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
 */

#include <vector>
#include <cstdio>
#include <map>

using namespace std;

struct scc{
  int V, c;
  vector<vector<int> > g, rg;
  vector<int> ord;
  vector<int> cmp;
  vector<bool> vis;
  scc(int V) : V(V), g(V), rg(V), ord(V, -1), 
	       cmp(V, -1), vis(V), c(0) {}
  
  void add_edge(int from, int to){
    g[from].push_back(to);
    rg[to].push_back(from);
  }

  void dfs(int i){
    vis[i] = true;
    for(int j = 0; j < g[i].size(); j++)
      if(!vis[g[i][j]]) dfs(g[i][j]);
    ord[c++] = i;
  }
  void rdfs(int i, int label){
    vis[i] = true;
    cmp[i] = label;
    for(int j = 0; j < rg[i].size(); j++) 
      if(!vis[rg[i][j]]) rdfs(rg[i][j], label);
  }

  int decomp(){
    int res = 0;
    fill(vis.begin(), vis.end(), false);
    for(int i = 0; i < V; i++)
      if(!vis[i]) dfs(i);
    
    fill(vis.begin(), vis.end(), false);
    for(int i = c - 1; i >= 0; i--)
      if(!vis[ord[i]]) rdfs(ord[i], res++);
    return res;
  }
};

int main(){
  int V, E;
  while(1){
    scanf("%d", &V);
    if(!V) break;
    
    scanf("%d", &E);
  
    scc scc(V);
    for(int i = 0; i < E; i++){
      int s, t;
      scanf("%d %d", &s, &t);
      scc.add_edge(s - 1, t - 1);
    }
    scc.decomp();

    map<int, int> outdegree;
    for(int i = 0; i < V; i++)
      outdegree[i] = 0;
    for(int i = 0; i < V; i++){
      for(int j = 0; j < scc.g[i].size(); j++){
	int to = scc.g[i][j];
	if(scc.cmp[i] == scc.cmp[to]) continue;
	outdegree[scc.cmp[i]]++;
      }
    }
    for(int i = 0; i < V; i++)
      if(outdegree[scc.cmp[i]] == 0)
	printf("%d ", i + 1);
    puts("");
  }
}
