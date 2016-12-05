// Time-stamp: <Tue Nov 01 21:28:13 東京 (標準時) 2016>
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

int code(char c){
  if(c == '_') return 0;
  if(c == '.') return 27;
  return c - 'a' + 1;
}
char invcode(int c){
  if(c == 0) return '_';
  if(c == 27) return '.';
  return (char)(c + 'a' - 1);
}
int unify(int a, int w){
  return (a % w + w) % w;
}
int main(int argc, char **argv){
  int K;
  string s;
  while(cin >> K){
    if(K == 0) break;
    cin >> s;

    int p[71];
    for(int i = 0; i < s.size(); i++) 
      p[K * i % s.size()] = (code(s[i]) + i) % 28;
    for(int i = 0; i < s.size(); i++) 
      cout << invcode(p[i]);
    cout << endl;
  }
  return 0;
}