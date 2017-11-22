// Time-stamp: <Thu May 04 00:18:55 東京 (標準時) 2017>
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

int d[50001];
int L, N, M;

bool C(int w){
  int pos = 0;
  int remove = 0;
  for(int i = 0; i < N; i++){
    if(d[i] - pos < w) remove++;
    else pos = d[i];
  }
  return remove <= M;
}

int main(int argc, char **argv){
  scanf("%d %d %d", &L, &N, &M);
  for(int i = 0; i < N; i++)
    scanf("%d", d + i);
  if(N == 0){
    printf("%d\n", L);
    return 0;
  }
  d[N++] = L;
  sort(d, d + N);
  
  int ub = L, lb = 0;
  while(lb < ub){
    int mid = (ub + lb) / 2;
    if(C(mid)) lb = mid + 1;
    else ub = mid;
  }
  printf("%d\n", ub - 1);
  return 0;
}
