// Time-stamp: <Mon Dec 12 22:32:56 東京 (標準時) 2016>
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
  int n;
  while(cin >> n, n){
    map<int, vector<string> > p;
    int K = INF;
    for(int i = 0; i < n; i++){
      string s; cin >> s;
      reverse(ALL(s));
      p[s.size()].push_back(s);
      K = min(K, (int)s.size());
    }

    int ans = INF;
    map<int, vector<string> >::iterator it = p.begin();
    for(; it != p.end(); it++){
      vector<string> t = it->second;
      sort(ALL(t));
      
      int w;
      for(w = it->first; w >= 1; w--){
	if(t.size() == 1) continue;
	for(int h = 1; h < t.size(); h++)
	  if(t[h - 1].substr(0, w) == t[h].substr(0, w)) goto L1;
      }
    L1:;
      ans = min(ans, min(it->first - w - 1, it->first - 1));
      //cout << it->first << " " << w << endl;
    }
    //dump(ans);
    ans = max(ans, 0);
    cout << ans << endl;
  }
  return 0;
}
