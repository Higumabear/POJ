// Time-stamp: <Sat Oct 29 23:19:58 東京 (標準時) 2016>
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
  string s, t;
  cin >> s >> t;
  map<char, int> a, b;
  for(int i = 0; i < s.size(); i++) a[s[i]]++;
  for(int i = 0; i < t.size(); i++) b[t[i]]++;

  vector<int> c, d;
  map<char, int>::iterator it = a.begin();
  for(; it != a.end(); it++) c.push_back(it->second);
  it = b.begin();
  for(; it != b.end(); it++) d.push_back(it->second);
  sort(ALL(c));
  sort(ALL(d));
  cout << (c == d ? "YES" : "NO") << endl;
  return 0;
}
