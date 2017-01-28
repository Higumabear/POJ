#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);

char c[2010];
int main(int argc, char **argv){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> c[i];

  int l = 0, r = n - 1, cnt = 0;
  while(l <= r){
    if(cnt && cnt % 80 == 0) cout << endl;
    if(c[l] < c[r])      cout << c[l++];
    else if(c[l] > c[r]) cout << c[r--];
    else{
      int tmpl = l, tmpr = r;
      while(tmpl < tmpr && c[tmpl] == c[tmpr]) tmpl++, tmpr--;
      if(r <= l || c[tmpl] < c[tmpr]) cout << c[l++];
      else cout << c[r--];
    }
    cnt++;
  }
  cout << endl;
  return 0;
}
