// Time-stamp: <Mon Nov 07 22:35:25 東京 (標準時) 2016>
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
    if(s == "*") break;
    bool sur = true;
    for(int w = 1; w <= s.size() - 1; w++){
      set<string> f;
      for(int i = 0; i + w < s.size(); i++){
	string t;
	t += s[i];
	t += s[i + w];
	f.insert(t);
      }
      if(f.size() != s.size() - w) sur = false;
    }
    cout << s << " is" << (sur ? "" : " NOT") << " surprising." << endl;
  }
  return 0;
}
