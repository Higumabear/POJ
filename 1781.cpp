// Time-stamp: <Thu Jan 05 22:16:11 東京 (標準時) 2017>
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

int rec(int n){
  if(n == 1) return 1;
  return n % 2 ? 2 * rec(n / 2) + 1 : 2 * rec(n / 2) - 1;
}
int main(int argc, char **argv){   
  while(1){
    string s; cin >> s;
    if(s == "00e0") break;
    int N = (s[0] - '0') * 10 + (s[1] - '0');
    for(int i = 0; i < (s[3] - '0'); i++) N *= 10;
    cout << rec(N) << endl;
  }
  return 0;
}
