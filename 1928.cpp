// Time-stamp: <Tue Mar 07 20:56:46 東京 (標準時) 2017>
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
  int T; cin >> T;
  while(T--){
    int W, H, TIME;
    cin >> H >> W >> TIME;
    
    vector<pair<int, int> > p;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
	int a; cin >> a;
	if(a) p.push_back(make_pair(a, i * W + j));
      }
    }
    sort(p.rbegin(), p.rend());
    
    vector<int> d(p.size());
    for(int i = 0; i < p.size(); i++){
      if(i == 0) d[0] = p[0].second / W + 1;
      else{
	d[i] = d[i - 1] + abs(p[i - 1].second / W - p[i].second / W)
	  + abs(p[i - 1].second % W - p[i].second % W);
      }
    }
    int ans = 0;
    for(int i = 0; i < p.size(); i++){
      int score = 0;
      if(d[i] + p[i].second / W + 1 + (i + 1) <= TIME){
	for(int j = 0; j <= i; j++) score += p[j].first;
	// cout << p[i].first << " " 
	//      << d[i] + p[i].second / W + 1 + (i + 1) << endl;
      }
	// cout << "#" << p[i].first << " " 
	//      << d[i] + p[i].second / W + 1 + (i + 1) << endl;
      ans = max(ans, score);
    }
    cout << ans << endl;
  }
  return 0;
}
