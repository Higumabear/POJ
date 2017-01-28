// Time-stamp: <Tue Jan 10 22:25:15 東京 (標準時) 2017>
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

char inc(char c){
  if(c <= '9') return (char)((int)(c - '0' + 1) % 10 + '0');
  return c;
}
char dec(char c){
  if(c <= '9') return (char)((int)(c - '0' + 9) % 10 + '0');
  return c;
}
int main(int argc, char **argv){
  int n;
  cin >> n;
  while(n--){
    string m, s;
    cin >> m >> s;
    for(int i = m.size() - 1; i >= 0; i--){
      if(m[i] == 'J') rotate(s.rbegin(), s.rbegin() + 1, s.rend());
      if(m[i] == 'C') rotate(s.begin(), s.begin() + 1, s.end());
      if(m[i] == 'E'){
	int L = s.size();
	for(int j = 0; j < L / 2; j++) swap(s[j], s[j + (L + 1) / 2]);
      }
      if(m[i] == 'A') reverse(ALL(s));
      if(m[i] == 'P') for(int j = 0; j < s.size(); j++) s[j] = dec(s[j]);
      if(m[i] == 'M') for(int j = 0; j < s.size(); j++) s[j] = inc(s[j]);
    }
    cout << s << endl;
  }
  return 0;
}
