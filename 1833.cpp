// Time-stamp: <Thu Nov 10 22:03:25 東京 (標準時) 2016>
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
  scanf("%d", &N);
  while(N--){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    for(int i = 0; i < k; i++)
      next_permutation(ALL(v));
    
    for(int i = 0; i < n; i++)
      printf("%d ", v[i]);
    printf("\n");
  }
  return 0;
}