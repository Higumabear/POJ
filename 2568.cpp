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

vector<int> g[60];

void rec(int idx, int prev){
  cout << "(" << idx;
  for(int i = 0; i < g[idx].size(); i++){
    if(g[idx][i] == prev) continue;
    cout << " ";
    rec(g[idx][i], idx);
  }
  cout << ")";
}

int main(){
  string s;
  while(getline(cin, s)){
    stringstream ss(s);
    vector<int> x;
    int v;
    while(ss >> v) x.push_back(v);
    for(int i = 0; i < 60; i++) g[i].clear();

    int N = x.size() + 1;
    for(int i = 0; i < N - 1; i++){
      int j;
      for(j = 1; j <= N; j++)
	if(!count(x.begin() + i, x.end(), j)) break;
      g[x[i]].push_back(j);
      g[j].push_back(x[i]);
      x.push_back(j);
    }
    rec(1, -1);
    cout << endl;
  }
  return 0;
}
