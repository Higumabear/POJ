// Time-stamp: <Sat Feb 25 19:46:33 東京 (標準時) 2017>
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

int main(int argc, char **argv){
  while(1){
    vector<pair<int, int> > p;
    int s, t;
    while(cin >> s >> t, s + t){
      if(s == -1 && t == -1) return 0;
      p.push_back(make_pair(s, t));
    }
    sort(ALL(p));
    p.push_back(make_pair(30, 30));
    
    vector<bool> vis(p.size(), false);
    int cnt = 0, ans = 0;
    while(cnt < p.size()){
      int y = 0, x = 0;
      ans++;
      for(int i = 0; i < p.size(); i++){
	if(vis[i]) continue;
	if(y <= p[i].first && x <= p[i].second){
	  cnt++;
	  vis[i] = true;
	  y = p[i].first;
	  x = p[i].second; 
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
