// Time-stamp: <Mon Mar 13 22:05:32 東京 (標準時) 2017>
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

string pa;

double lgo(int idx){
  idx--;
  while(0 <= idx){
    if(pa[idx] == '|' || pa[idx] == '\\') return 0.0;
    if(pa[idx] == '.') return 1.0;
    idx--;
  }
  return 1.0;
}

double rgo(int idx){
  idx++;
  while(idx < pa.size()){
    if(pa[idx] == '|' || pa[idx] == '/') return 0.0;
    if(pa[idx] == '.') return 1.0;
    idx++;
  }
  return 1.0;
}

int main(int argc, char **argv){
  while(cin >> pa){
    if(pa == "#") break;
    
    double ans = 0;
    for(int i = 0; i < pa.size(); i++){

      if(pa[i] == '.') ans += 1.0;
      if(pa[i] == '/') ans += lgo(i);
      if(pa[i] == '\\') ans += rgo(i);
      if(pa[i] == '|')
	ans += 0.5 * rgo(i) + 0.5 * lgo(i);
    }
    cout << (int)(ans / pa.size() * 100) << endl;
  }
  return 0;
}
