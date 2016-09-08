// Time-stamp: <Wed Aug 17 20:54:36 東京 (標準時) 2016>
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
  while(scanf("%d", &N), N){
    vector<int> cur(N), next;
    for(int i = 0; i < N; i++) scanf("%d", &cur[i]);
    next = cur;

    for(int i = 0; i < log2(N); i++){
      int w = 1 << i;
      for(int j = 0; j < (1 << i); j++){
	int s = cur[j], t = cur[j + w];
	next[2 * j] = (s + t) / 2;
	next[2 * j + 1] = (s - t) / 2;      
      }
      cur = next;
    }
    for(int i = 0; i < N; i++)
      printf("%d ", cur[i]);
    printf("\n");
  }
  return 0;
}
