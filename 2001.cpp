// Time-stamp: <Sat Dec 03 01:20:33 東京 (標準時) 2016>
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
  char c[21];
  vector<string> na;
  while(gets(c)) na.push_back(string(c));
  for(int i = 0; i < na.size(); i++){
    int j;
    for(j = 1; j <= na[i].size(); j++){
      if(j == na[i].size()) break;
      string s = na[i].substr(0, j);
      bool check = true;
      for(int k = 0; k < na.size(); k++)
	if(na[k].substr(0, j) == s && i != k) check = false;
      if(check){
	cout << na[i] << " " << s << endl;
	goto L1;
      }
    }
    cout << na[i] << " " << na[i] << endl;
  L1:;
  }
  return 0;
}
