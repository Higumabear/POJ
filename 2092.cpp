// Time-stamp: <Thu Aug 04 23:47:48 東京 (標準時) 2016>
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

using namespace std;

int main(int argc, char **argv){
  int N, M;
  while(scanf("%d %d", &N, &M), N, M){
    map<int, int> app;
    int t;
    for(int i = 0; i < N * M; i++){
      scanf("%d", &t);
      app[t]++;
    }
    vector<pair<int, int> > pa;
    map<int, int>::iterator it = app.begin();
    for(; it != app.end(); it++) 
      pa.push_back(make_pair(-it->second, it->first));
    sort(ALL(pa));
    for(int i = 1; pa[1].first == pa[i].first; i++){
      if(i > 1) cout << " ";
      cout << pa[i].second;
    }
    cout << endl;
  }
  return 0;
}
