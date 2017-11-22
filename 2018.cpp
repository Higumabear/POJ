// Time-stamp: <Tue Apr 04 00:29:17 東京 (標準時) 2017>
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

int N, F;
int A[100001];
ll sum[100001];
ll rmq[211111];

bool av(int x){
  sum[0] = 0;
  for(int i = 0; i < N; i++)
    sum[i + 1] = sum[i] + A[i] - x;
  FILL(rmq, -LLINF);
  rmq[N] = sum[N];

  for(int i = N - 1; i >= 0; i--)
    rmq[i] = max(rmq[i + 1], sum[i]);
  for(int i = 0; i < N; i++)
    if(rmq[i + F] - sum[i] >= 0) return true;
  return false;
}

int main(int argc, char **argv){
  scanf("%d %d", &N, &F);
  for(int i = 0; i < N; i++){
    scanf("%d", A + i);
    A[i] *= 1000;
  }
  
  int ub = 2000 * 1000 + 100;
  int lb = 0;
  while(lb + 1 < ub){
    int mid = (ub + lb) / 2;
    if(av(mid)) lb = mid;
    else ub =mid;
  }
  printf("%d\n", lb);
  return 0;
}
