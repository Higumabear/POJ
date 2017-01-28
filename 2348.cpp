// Time-stamp: <Tue Jan 10 23:24:42 東京 (標準時) 2017>
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

vector<int> d;
int euc(int a, int b){
  if(b) d.push_back(a / b);
  return b == 0 ? a : euc(b, a % b);
}
int main(int argc, char **argv){
  int a, b;
  while(cin >> a >> b, a){
    d.clear();
    if(a < b) swap(a, b);
    euc(a, b);
    d[d.size() - 1]++;

    for(int i = 0; i < d.size(); i++){
      if(d[i] >= 2){
	cout << (i % 2 ? "Ollie" : "Stan") << " wins" << endl;
	break;
      }
    }
  }
  return 0;
}
