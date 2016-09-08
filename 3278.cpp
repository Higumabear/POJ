// Time-stamp: <Wed Aug 10 22:00:33 東京 (標準時) 2016>
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
const int MAXN = 200000;
int d[MAXN + 1];

int main(int argc, char **argv){
  int N, K;
  cin >> N >> K;
  FILL(d, -1);
  d[N] = 0;
  
  queue<int> Q;
  Q.push(N);
  while(!Q.empty()){
    int pos = Q.front(); Q.pop();
    if(pos == K) {
      cout << d[pos] << endl;
      return 0;
    }
    if(pos + 1 <= MAXN && d[pos + 1] == -1){
      Q.push(pos + 1);
      d[pos + 1] = d[pos] + 1;
    }
    if(0 <= pos - 1 && d[pos - 1] == -1){
      Q.push(pos - 1);
      d[pos - 1] = d[pos] + 1;
    }
    if(2 * pos <= MAXN && d[2 * pos] == -1){
      Q.push(2 * pos);
      d[2 * pos] = d[pos] + 1;
    }
  }
  return 0;
}
