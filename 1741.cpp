#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int NUM = 10100;

struct edge{ int to, length; };

vector<edge> g[NUM];
int subtree[NUM], depth[NUM];
bool centroid[NUM];

int N, K;

void add_edge(int u, int v, int l){
  g[u].push_back((edge){v, l});
  g[v].push_back((edge){u, l});
}


void count_subtree(int idx, int prev){
  subtree[idx] = 1;
  for(int i = 0; i < g[idx].size(); i++){
    int nxt = g[idx][i].to;
    if(nxt == prev || centroid[nxt]) continue;
    count_subtree(nxt, idx);
    subtree[idx] += subtree[nxt];
  }
}

void enumerate_path(int idx, int prev, int len, vector<int> &d){
  d.push_back(len);
  for(int i = 0; i < g[idx].size(); i++){
    int nxt = g[idx][i].to;
    if(nxt == prev || centroid[nxt]) continue;
    enumerate_path(nxt, idx, len + g[idx][i].length, d);
  }
}

// int find_centroid(int idx, int prev, int sz){
//   for(int i = 0; i < g[idx].size(); i++){
//     int nxt = g[idx][i].to;
//     if(nxt != prev && subtree[nxt] > sz / 2)
//       return find_centroid(nxt, idx, sz);
//   }
//   return idx;
// }

pair<int, int> find_centroid(int idx, int prev, int t){
  pair<int, int> res(1 << 29, -1);
  int s = 1, m = 0;
  for(int i = 0; i < g[idx].size(); i++){
    int nxt = g[idx][i].to;
    if(nxt == prev || centroid[nxt]) continue;

    res = min(res, find_centroid(nxt, idx, t));
    m = max(m, subtree[nxt]);
    s += subtree[nxt];
  }
  m = max(m, t - s);
  res = min(res, pair<int, int>(m, idx));
  return res;
}

int count_pair(vector<int> &d){
  sort(d.begin(), d.end());
  int j = d.size();
  int res = 0;
  for(int i = 0; i < d.size(); i++){
    while(j > 0 && d[i] + d[j - 1] > K) j--;
    res += j - (j > i ? 1 : 0);
  }
  return res / 2;
}

int decompose(int idx){
  int ans = 0;

  count_subtree(idx, -1);
  int ctr = find_centroid(idx, -1, subtree[idx]).second;
  centroid[ctr] = true;

  for(int i = 0; i < g[ctr].size(); i++){
    int nxt = g[ctr][i].to;
    if(centroid[nxt]) continue;
    ans += decompose(nxt);
  }

  vector<int> ds;
  ds.push_back(0);
  for(int i = 0; i < g[ctr].size(); i++){
    int nxt = g[ctr][i].to;
    if(centroid[nxt]) continue;

    vector<int> tds;
    enumerate_path(nxt, ctr, g[ctr][i].length, tds);
    ans -= count_pair(tds);
    ds.insert(ds.end(), tds.begin(), tds.end());
  }
  ans += count_pair(ds);
  centroid[ctr] = false;

  return ans;
}

int main(){
  while(scanf("%d %d", &N, &K), N + K){
    for(int i = 0; i < N; i++){
      g[i].clear();
      centroid[i] = false;
      subtree[i] = 0;
    }
    
    int a, b, c;
    for(int i = 0; i < N - 1; i++){
      scanf("%d %d %d", &a, &b, &c);
      a--, b--;
      add_edge(a, b, c);
    }

    printf("%d\n", decompose(0));
  }
}
