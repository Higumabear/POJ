// Time-stamp: <Mon Mar 13 22:29:10 東京 (標準時) 2017>
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
  int T; cin >> T;
  for(int t = 0; t < T; t++){
    int L; cin >> L;
    
    int cnt = 0;
    string s1, s2, r;
    cin >> s2 >> s1 >> r;
    string s(L * 2, ' ');
    for(int i = 0; i < 10000; i++){
      for(int i = 0; i < L; i++){
	s[2 * i] = s1[i];
	s[2 * i + 1] = s2[i];
      }
      cnt++;
      if(s == r) break;
      s1 = s.substr(L);
      s2 = s.substr(0, L);
    }
    cout << t + 1 << " " << (cnt == 10000 ? -1 : cnt) << endl;
  }
  return 0;
}
