#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int MAX_V = 1000;
const int INF = 10000000;

struct edge{ int to, cap, cost, rev; };

int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

int min(int a, int b){
  return (a > b) ? b : a;
}

void add_edge(int from, int to, int cap, int cost){
  G[from].push_back((edge){to, cap, cost, G[to].size()});
  G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f){
  int res = 0;
  fill(h, h + V, 0);
  while(f > 0){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      int v = p.second;
      if(dist[v] < p.first) continue;
      for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
    if(dist[t] == INF){
      return -1; // もうこれ以上流せない
    }
    for(int v = 0; v < V; v++) h[v] += dist[v];
    //s-t最短路にそって目一杯流す
    int d = f;
    for(int v = t; v != s; v = prevv[v]){
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -=d;
    res += d * h[t];
    for(int v = t; v != s; v = prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

int l, F;

int main()
{
  int N, M;
  while(cin >> N >> M, N + M){
    for(int i = 0; i < MAX_V; i++) G[i].clear();
    vector<pair<int, int> > posH, posm;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	char c; cin >> c;
	if(c == 'H') posH.push_back(make_pair(i, j));
	if(c == 'm') posm.push_back(make_pair(i, j));
      }
    }
    int s = posH.size() + posm.size(), t = s + 1;
    V = posH.size() + posm.size() + 2;
    for(int i = 0; i < posm.size(); i++){
      for(int j = 0; j < posH.size(); j++){
	add_edge(i, j + posm.size(), 1,
		 abs(posm[i].first - posH[j].first) +
		 abs(posm[i].second - posH[j].second));
      }
    }
    for(int i = 0; i < posm.size(); i++)
      add_edge(s, i, 1, 0);
    for(int i = 0; i < posH.size(); i++)
      add_edge(posm.size() + i, t, 1, 0);
    cout << min_cost_flow(s, t, posm.size()) << endl;
  }
  return 0;
}
