// Time-stamp: <Mon Feb 27 21:44:27 東京 (標準時) 2017>
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

vector<vector<pair<int, int> > > g;

void add_edge(int from, int to, int cost){//2way
  g[from].push_back(make_pair(to, cost));
  g[to].push_back(make_pair(from, cost));
}

int prim(){
  int V = g.size();
  priority_queue<pair<int, int> > Q;
  vector<bool> use(V, false);
  Q.push(make_pair(INF, 0));

  int ret = 0;
  while(!Q.empty()){
    pair<int, int> e = Q.top(); Q.pop();
    int to = e.second;
    if(use[to]) continue;
    use[to] = true;
    if(to == V - 1){
      ret = e.first;
      break;
    }

    for(int i = 0; i < g[to].size(); i++)
      if(!use[g[to][i].first]) 
	Q.push(make_pair(min(e.first, g[to][i].second), g[to][i].first)); 
  }  
  return ret;
}

int main(int argc, char **argv){
  int V, E, cases = 0;
  while(cin >> V >> E, V + E){
    g.clear();
    g.resize(V);
    
    map<string, int> idx;
    vector<string> s(E), t(E);
    vector<int> ton(E);
    for(int i = 0; i < E; i++)
      cin >> s[i] >> t[i] >> ton[i];
    
    string a, b;
    cin >> a >> b;
    idx[a] = 0, idx[b] = V - 1;
    int label = 0;
    for(int i = 0; i < E; i++){
      if(!idx.count(s[i])) idx[s[i]] = label++;
      if(!idx.count(t[i])) idx[t[i]] = label++;
      add_edge(idx[s[i]], idx[t[i]], ton[i]);
    }

    cout << "Scenario #" << cases++ + 1 << "\n";
    cout << prim() << " tons" << endl << endl;;
  }
  return 0;
}
