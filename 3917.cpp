// Time-stamp: <Wed Dec 14 21:29:41 東京 (標準時) 2016>
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
  string p1, p2;
  while(cin >> p1 >> p2){
    int w1 = 0, w2 = 0;
    if(p1 == "E") break;
    for(int i = 0; i < p1.size(); i++){
      if(p1[i] == p2[i]) continue;
      else if(p1[i] == 'R')
	p2[i] == 'S' ? w1++ : w2++;
      else if(p1[i] == 'P')
	p2[i] == 'R' ? w1++ : w2++;
      else //S
	p2[i] == 'P' ? w1++ : w2++;
    }
    cout << "P1: " << w1 << endl;
    cout << "P2: " << w2 << endl;
  }
  return 0;
}
