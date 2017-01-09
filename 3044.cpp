// Time-stamp: <Fri Dec 23 15:17:12 東京 (標準時) 2016>
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

int d[1000100];
int main(int argc, char **argv){
  int N, W, prevx = 0, prevy = 0;
  scanf("%d %d", &N, &W);
  d[0] = 0;
  for(int k = 0; k < N; k++){
    int x, y;
    scanf("%d %d", &x, &y);
    if(k) for(int i = prevx; i < x; i++) d[i] = prevy;
    prevx = x, prevy = y;
  }
  for(int i = prevx; i <= W; i++) d[i] = prevy;
  d[W + 1] = 0;

  int ans = 0;
  deque<int> deq;
  for(int i = 0; i <= W + 1; i++){
    if(deq.empty() || deq.back() != d[i]){
      //cout << '.' << string(d[i], 'X') << endl;
      while(!deq.empty() && deq.back() >= d[i]){
	if(deq.back() != d[i]) ans++;
	deq.pop_back();
      }
      deq.push_back(d[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
