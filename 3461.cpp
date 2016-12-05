// Time-stamp: <Thu Nov 10 21:23:40 東京 (標準時) 2016>
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

// vector<int> boyer_moore(string text, string pattern){
//   int N = text.length(), M = pattern.length();
//   vector<int> skip(0x100, M);
//   for(int i = 0; i < M; i++) skip[pattern[i]] = M - i + 1;

//   vector<int> pos;
//   for(int i = M - 1; i < N; ){
//     int j = M - 1;
//     while(j >= 0 && text[i] == pattern[j]) i--, j--;
//     if(j < 0){
//       pos.push_back(i + 1);
//       i += M + 1;
//     }
//     else i += skip[text[i]];
//   }
//   return pos;
// }

struct knuth_morris_pratt {
  int m;
  const char *p;
  vector<int> fail;
  knuth_morris_pratt(const char *p) : p(p), m(strlen(p)) {
    fail.resize(m+1, -1);
    for (int i = 1, j = -1; i <= m; ++i) {
      while (j >= 0 && p[j] != p[i-1]) j = fail[j];
      fail[i] = ++j;
    }
  }
  vector<int> match(const char *s) {
    int n = strlen(s);
    vector<int> occur;
    for (int i = 0, k = 0; i < n; ++i) {
      while (k >= 0 && s[i] != p[k]) k = fail[k];
      if (++k == m) { 
        /* match at s[i-m+1 ... i] */
        occur.push_back(i-m+1);
	//occur++;
      }
    }
    return occur;
  }
};

char p[10010], t[1000010];
int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  while(N--){
    // string p, t;
    // cin >> p >> t;
    //cout << boyer_moore(t, p) << endl;
    scanf("%s\n%s", p, t);
    knuth_morris_pratt kmp(p);
    vector<int> v = kmp.match(t);
    // for(int i = 0; i < v.size(); i++) 
    //   cout << v[i] << endl;
    cout << v.size() << endl;
  }
  return 0;
}
