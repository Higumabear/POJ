#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int> > g[10010];
int dist[10010];

void rec(int idx, int sofar){
  dist[idx] = sofar;
  for(int i = 0; i < g[idx].size(); i++){
    pair<int, int> nxt = g[idx][i];
    if(dist[nxt.first] != -1) continue;
    rec(nxt.first, nxt.second + sofar);
  }
  return ;
}

int main(){
  int u, v, w;
  while(cin >> u >> v >> w){
    g[u - 1].push_back(make_pair(v - 1, w));
    g[v - 1].push_back(make_pair(u - 1, w));
  }

  fill(dist, dist + 10010, -1);
  rec(0, 0);

  int x = max_element(dist, dist + 10010) - dist;
  fill(dist, dist + 10010, -1);
  rec(x, 0);
  cout << *max_element(dist, dist + 10010) << endl;
}
