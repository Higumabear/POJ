// Time-stamp: <Mon Aug 08 22:30:08 東京 (標準時) 2016>
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
  int N;
  while(cin >> N, N){
    vector<int> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];
    int G; cin >> G;
    
    while(G--){
      sort(ALL(p));
      p[0]++, p[1]++, p[2]++;
    }
    cout << (*max_element(ALL(p)) + 49) / 50 << endl;
  }
  return 0;
}
