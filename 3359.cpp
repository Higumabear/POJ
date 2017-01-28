// Time-stamp: <Sun Jan 15 14:56:26 東京 (標準時) 2017>
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
  string s;
  while(cin >> s){

    int L = s.size();
    string t(s);
    int md = -1;
    string ans;
    for(int i = 0; i < 10; i++){
      next_permutation(ALL(t));

      int v = INF;
      for(int j = 0; j < L - 1; j++) v = min(v, abs(t[j] - t[j + 1]));
      if(md < v || md == v && t < ans){
	md = v; ans = t;
      }
    }
    t = s;
    for(int i = 0; i < 10; i++){
      prev_permutation(ALL(t));

      int v = INF;
      for(int j = 0; j < L - 1; j++) v = min(v, abs(t[j] - t[j + 1]));
      if(md < v || md == v && t < ans){
	md = v; ans = t;
      }
    }
    cout << ans << md << endl;
  }
  return 0;
}
