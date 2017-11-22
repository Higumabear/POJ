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

void centrize(vector<pair<int, int> > &p){
  int x = p[0].first, y = p[0].second;
  for(int i = 0; i < p.size(); i++)
    p[i].first -= x, p[i].second -= y;
}

void rot90(vector<pair<int, int> > &p){
  for(int i = 0; i < p.size(); i++)
    p[i] = make_pair(-p[i].second, p[i].first);
}

bool same(vector<pair<int, int> > a, vector<pair<int, int> > b){
  int dx = a[0].first - b[0].first, dy = a[0].second - b[0].second;
  if(a.size() != b.size()) return false;
  for(int i = 0; i < a.size(); i++)
    if(a[i].first - b[i].first != dx || a[i].second - b[i].second != dy)
      return false;
  return true;
}

int main(){
  int T;
  while(cin >> T, T){
    vector<pair<int, int> > p[T + 1];
    for(int j = 0; j <= T; j++){
      int N; cin >> N;
      for(int i = 0; i < N; i++){
	int x, y;
	cin >> x >> y;
	p[j].push_back(make_pair(x, y));
      }
    }

    vector<int> ans;
    for(int j = 1; j <= T; j++){
      //centrize(p[j]);
      for(int k = 0; k < 4; k++){
	rot90(p[j]);
	if(same(p[0], p[j])) ans.push_back(j);
      }

      reverse(ALL(p[j]));
      //centrize(p[j]);
      for(int k = 0; k < 4; k++){
	rot90(p[j]);
	if(same(p[0], p[j])) ans.push_back(j);
      }
    }
    ans.erase(unique(ALL(ans)), ans.end());
    for(int i = 0; i < ans.size(); i++)
      cout << ans[i] << endl;
    cout << "+++++" << endl;
  }
  return 0;
}
