#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
#include <math.h>

using namespace std;

const int INF = 1 << 29;

typedef pair<int, int> PII;

pair<double, vector<PII> >
prim(const vector<vector<double> > &g){
  int V = g.size();
  //priority_queue<pair<int, PII> > Q;
  priority_queue<pair<double, PII> ,
  		 vector<pair<double, PII> >,
  		 greater<pair<double, PII> > > Q;

  vector<bool> used(V, false);
  double res = 0;
  vector<PII> edges;

  Q.push(make_pair(0, make_pair(-1, 0)));
  while(!Q.empty()){
    double cost = Q.top().first;
    PII e = Q.top().second; Q.pop();

    int cur = e.second, prev = e.first;
    if(used[cur]) continue;
    used[cur] = true;
    if(prev != -1){
      res += cost;
      edges.push_back(e);
    }
    for(int next = 0; next < V; next++)
      if(!used[next] && g[cur][next] != INF)
  	Q.push(make_pair(g[cur][next], make_pair(cur, next)));
  }
  return make_pair(res, edges);
}

double x[110], y[110], z[110], r[110];

int main(){
  int n;
  while(cin >> n, n){
    for(int i = 0; i < n; i++)
      cin >> x[i] >> y[i] >> z[i] >> r[i];
    
    vector<vector<double> > g(n, vector<double>(n));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	g[i][j] = max(0.0, sqrt(pow(x[i] - x[j], 2.0) +
				pow(y[i] - y[j], 2.0) +
				pow(z[i] - z[j], 2.0)) - r[i] - r[j]); 

    pair<double, vector<PII> > mst = prim(g);
    printf("%.3lf\n", mst.first);
  }
}
