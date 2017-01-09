// Time-stamp: <Mon Dec 26 22:21:59 東京 (標準時) 2016>
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

void chbig(string &s, string &t){ // check whether s < t
  if(s.size() < t.size()) s = t;
  else if(s.size() > t.size());
  else {
    if(s > t) s = t;
  }
}
int main(int argc, char **argv){
  int T; cin >> T;
  while(T--){
    int N; cin >> N;
    vector<string> s(N);
    for(int i = 0; i < N; i++) cin >> s[i];
    
    int ans = 0;
    string ret;
    for(int i = 0; i < s[0].size(); i++){
      for(int l = s[0].size() - i; l >= 0; l--){
	if(ans > l) break;
	bool good = true;
	string cand = s[0].substr(i, l);
	//cout << cand << endl;
	for(int idx = 1; idx < N; idx++){
	  if(s[idx].find(cand) == string::npos){
	    good = false;
	    break;
	  }
	}
	if(good){
	  ans = l;
	  chbig(ret, cand);
	}
      }
    }
    if(ans < 3)
      cout << "no significant commonalities" << endl;
    else
      cout << ret << endl;
  }
  return 0;
}
