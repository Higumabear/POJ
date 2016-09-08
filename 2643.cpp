// Time-stamp: <Mon Jun 06 23:18:56 東京 (標準時) 2016>
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

map<string, string> party;
map<string, int> ballot;

int main(int argc, char **argv){
  int N, M;
  string s, t, discard;
  cin >> N;
  getline(cin, discard);
  for(int i = 0; i < N; i++){
    getline(cin, s);
    getline(cin, t);
    party[s] = t;
  }
  cin >> M;
  getline(cin, discard);
  for(int i = 0; i < M; i++){
    getline(cin, s);
    ballot[s]++;
  }

  vector<pair<int, string>> p;
  map<string, int>::iterator it = ballot.begin();
  for(; it != ballot.end(); it++)
    p.push_back(make_pair(it->second, it->first));

  sort(p.rbegin(), p.rend());
  if(p[0].first == p[1].first) cout << "tie" << endl;
  else cout << party[p[0].second] << endl;
  return 0;
}
