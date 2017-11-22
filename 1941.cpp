// Time-stamp: <Sat Feb 25 19:04:07 東京 (標準時) 2017>
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
  vector<string> s[12];
  s[1].push_back(" /\\ ");
  s[1].push_back("/__\\");
  for(int i = 2; i <= 10; i++){
    string sp(s[i - 1][0].size() / 2, ' ');
    for(int j = 0; j < s[i - 1].size(); j++)
      s[i].push_back(sp + s[i - 1][j] + sp);
    for(int j = 0; j < s[i - 1].size(); j++)
      s[i].push_back(s[i - 1][j] + s[i - 1][j]);
  }
  int t;
  while(cin >> t, t){
    for(int i = 0; i < s[t].size(); i++)
      cout << s[t][i] << endl;
    cout << endl;
  }
  
  return 0;
}
