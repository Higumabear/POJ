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

int T;
map<string, int> idx;
map<int, string> ridx;
vector<pair<int, int> > g[101];

struct desc{
  int age;
  string name;
  bool operator<(const desc &r)const{
    if(age == r.age) return name < r.name;
    return age > r.age;
  }
};

vector<desc> ans;

void rec(int v, int age){
  desc d;
  d.name = ridx[v];
  d.age = age;
  ans.push_back(d);
  for(int i = 0; i < g[v].size(); i++){
    int to = g[v][i].first;
    int x = g[v][i].second;
    rec(to, age - x);
  }
  return;
}


int main(){
  cin >> T;
  for(int t = 0; t < T; t++){
    for(int i = 0; i < 101; i++)
      g[i].clear();
    idx.clear();
    ridx.clear();
    ans.clear();
    
    int c = 1;
    idx["Ted"] = 0;
    ridx[0] = "Ted";

    int E;
    cin >> E;
    for(int i = 0; i < E; i++){
      string s, t;
      int age;
      cin >> s >> t >> age;
      if(!idx.count(s)){
	idx[s] = c;
	ridx[c] = s;
	c++;
      }
      if(!idx.count(t)){
	idx[t] = c;
	ridx[c] = t;
	c++;
      }
      g[idx[s]].push_back(make_pair(idx[t], age));
    }
    rec(0, 100);

    sort(ALL(ans));
    cout << "DATASET " << t + 1 << endl;
    for(int i = 1; i < ans.size(); i++)
      cout << ans[i].name << " " << ans[i].age << endl;
  }
  return 0;
}
