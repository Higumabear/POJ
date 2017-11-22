#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
struct spot{
  int idx, x, y;
  spot(int idx, int x, int y) : idx(idx), x(x), y(y) {}
};

vector<spot> v[110];

struct edge{
  int from, to;
  double cost;
  edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}
  bool operator<(const edge &r) const{ return cost < r.cost; }
  bool operator>(const edge &r) const{ return cost > r.cost; }
};

vector<edge> g[50000];

void add_edge(int from, int to, double cost){
  g[from].push_back(edge(from, to, cost));
}

int V;
int prev_node[100100];
double dist[100100];
double dijkstra(int s, int t){
  priority_queue<edge, vector<edge>, greater<edge> > Q;
  Q.push(edge(-2, s, 0));
  fill(dist, dist + V, 1e10);
  fill(prev_node, prev_node + V, -1);
  
  dist[s] = 0;
  while(!Q.empty()){
    edge e = Q.top(); Q.pop();
    if(prev_node[e.to] != -1) continue;

    prev_node[e.to] = e.from;
    for(int i = 0; i < g[e.to].size(); i++){
      edge f = g[e.to][i];
      if(dist[f.to] > dist[e.to] + f.cost){
	dist[f.to] = dist[e.to] + f.cost;
	Q.push(edge(f.from, f.to, f.cost + dist[e.to]));
      }
    }
  }  
  return dist[t];
}

int main(){
  cin >> N;
  V = 0;
  for(int i = 0; i < N; i++){
    int T; cin >> T;
    for(int j = 0; j < T; j++){
      int x, y; cin >> x >> y;
      v[i].push_back(spot(V++, x, y));
    }
  }
  for(int i = 0; i < v[0].size(); i++)
    v[N].push_back(spot(V++, v[0][i].x, v[0][i].y));

  //g.resize(V);
  for(int i = 1; i <= N; i++){
    vector<spot> p = v[i - 1];
    vector<spot> q = v[i];
    for(int a = 0; a < p.size(); a++){
      for(int b = 0; b < q.size(); b++){
	double d = sqrt((double)((p[a].x - q[b].x) * (p[a].x - q[b].x) + 
				 (p[a].y - q[b].y) * (p[a].y - q[b].y)));
	add_edge(p[a].idx, q[b].idx, d);
      }
    }
  }

  double ans = 1e10;
  for(int i = 0; i < v[0].size(); i++){
    double res = dijkstra(v[0][i].idx, v[N][i].idx);
    ans = min(ans, res);
  }
  cout << (int)(ans * 100) << endl;
  return 0;
}
