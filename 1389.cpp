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

struct rect{
  int lx, ly, rx, ry;
  rect(int lx, int ly, int rx, int ry) :
    lx(lx), ly(ly), rx(rx), ry(ry) {}
  bool operator<(const rect &r)const{
    return ly < r.ly;
  }
};

int main(){
  int lx, ly, rx, ry;
  while(cin >> lx >> ly >> rx >> ry, lx != -1){
    vector<rect> rs;
    vector<int> xs;
    rs.push_back(rect(lx, ly, rx, ry));
    xs.push_back(lx);
    xs.push_back(rx);
    while(cin >> lx >> ly >> rx >> ry, lx != -1){
      rs.push_back(rect(lx, ly, rx, ry));
      xs.push_back(lx);
      xs.push_back(rx);
    }
    sort(ALL(rs));
    sort(ALL(xs));

    const vector<int>::iterator last = unique(ALL(xs));
    ll ans = 0;
    vector<int>::iterator it = xs.begin(), jt;
    for(jt = it++; it != last; it++, jt++){
      ll w = *it - *jt;
      int l = -1, h = -1;
      for(vector<rect>::iterator kt = rs.begin(); kt != rs.end(); kt++){
	if(kt->lx <= *jt && *it <= kt->rx){
	  if(l == -1){
	    l = kt->ly;
	    h = kt->ry;
	  }else if(kt->ly <= h){
	    h = max(h, kt->ry);
	  }else{
	    ans += w * (h - l);
	    h = kt->ry;
	    l = kt->ly;
	  }
	}
      }
      if(l != -1)
	ans += w * (h - l);
    }
    cout << ans << endl;
  }
  
  return 0;
}
