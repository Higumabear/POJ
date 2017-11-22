// Time-stamp: <Thu Mar 02 00:10:33 東京 (標準時) 2017>
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
  int n, m, x1, y1, x2, y2;
  while(cin >> n, n){
    cin >> m >> x1 >>  y1 >> x2 >> y2;
    int dx = x1, dy = y2;
    x1 -= dx, y1 -= dy;
    x2 -= dx, y2 -= dy;

    vector<pair<int, int> > s(n + 1);
    for(int i = 0; i < n; i++){
      cin >> s[i].first >> s[i].second;
      s[i].first -= dx;
      s[i].second -= dy;
    }
    s[n].first = x2 - dx;
    s[n].second = x2 - dx;
    sort(ALL(s));

    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    map<int, int> cnt;
    for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;
      x -= dx, y -= dy;
      if(x1 <= x && x <= x2 && y2 <= y && y <= y1){
	//cout << x << " " << y << " " << endl;
	for(int j = 0; j <= n; j++){
	  double online = abs(y) / 1.0 / abs(y1) * (s[j].first - s[j].second) + s[j].second;
	  if(x <= online){
	    //cout << x << " " << y << " " << online << endl;
	    if(!cnt.count(j)) cnt[j] = 1;
	    else cnt[j]++;
	    break;
	  }
	}
      }
      //else 
      //cout << x << " " << y << " out" << endl;
    }
    map<int, int> mag;
    for(map<int, int>::iterator it = cnt.begin(); 
	it != cnt.end(); it++){
      if(!mag.count(it->second)) mag[it->second] = 1;
      else mag[it->second]++;
    }
    cout << "Box" << endl;
    for(map<int, int>::iterator it = mag.begin(); 
	it != mag.end(); it++){
      cout << it->first << ": " << it->second << endl;
    }
  }
  return 0;
}
