// Time-stamp: <Sun Oct 30 22:06:17 東京 (標準時) 2016>
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
  map<string, string> f;
  while(1){
    string s, t;
    getline(cin, s);
    if(s.size() < 2) break;
    stringstream ss(s);
    ss >> s >> t;
    f[t] = s;
  }
  
  string index;
  while(cin >> index) cout << (f.count(index) ? f[index] : "eh") << endl;
  return 0;
}
