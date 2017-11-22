// Time-stamp: <Tue Feb 14 22:46:13 東京 (標準時) 2017>
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
    vector<pair<int, string> > p;
    while(cin >> s){
      if(s == "END") break;
      int d, v;
      cin >> d >> v;
      p.push_back(make_pair(max(v - d, 1), s));
    }
    sort(p.rbegin(), p.rend());
    for(int i = 0; i < p.size(); i++)
      cout << p[i].second << endl;
    cout << endl;
  }
  return 0;
}
