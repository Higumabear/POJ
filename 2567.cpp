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

bool adj[60][60];

void parse(int par, string tree){
  int i = 0, v = 0;
  while(!isdigit(tree[i])) i++;
  for(; isdigit(tree[i]); i++)
    v = 10 * v + tree[i] - '0';

  if(par)
    adj[par][v] = adj[v][par] = true;
  
  int bracket = 0;
  string tmp;
  vector<string> subtree;
  for(; i < tree.size() - 1; i++){
    tmp.push_back(tree[i]);
    if(tree[i] == '(') bracket++;
    if(tree[i] == ')'){
      bracket--;
      if(bracket == 0){
	subtree.push_back(tmp);
	tmp.clear();
      }
    }
  }
  for(int j = 0; j < subtree.size(); j++)
    parse(v, subtree[j]);
}

priority_queue<pair<int, int> > Q;

void rec(int idx, int prev){
  if(count(adj[idx], adj[idx] + 60, true) == 1){
    int v = 0;
    while(!adj[idx][v]) v++;
    Q.push(make_pair(-idx, v));
  }

  for(int i = 0; i < 60; i++){
    if(adj[idx][i] && i != prev){
      //cout << idx << " -> " << i << endl;
      rec(i, idx);
    }
  }
  
}

int main(){
  string s;
  while(getline(cin, s)){
    FILL(adj, false);
    parse(0, s);

    while(1){
      Q = priority_queue<pair<int, int> >();
      int v;
      for(v = 0; v < 60; v++)
	if(count(adj[v], adj[v] + 60, true)) break;

      if(v == 60) break;
      
      rec(v, -1);
      
      int s = -Q.top().first, t = Q.top().second;
      Q.pop();
      cout << t << " ";
      adj[s][t] = adj[t][s] = false;
    }
    cout << endl;
  }
  return 0;
}
