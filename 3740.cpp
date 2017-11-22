// Time-stamp: <Wed Feb 01 01:36:42 東京 (標準時) 2017>
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
#include <bitset>

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


bool ok;
int M, N;
int m[16][300];
int cur[300];

void dfs(int idx){
  if(ok) return;
  if(idx == M){
    for(int i = 0; i < N; i++) 
      if(cur[i] != 1) return;
    ok = true;
    return;
  }
  dfs(idx + 1);

  int i;
  for(i = 0; i < N; i++){
    cur[i] += m[idx][i];
    if(cur[i] > 1) break;
  }
  if(i == N){
    dfs(idx + 1);
    for(i = N - 1; i >= 0; i--) cur[i] -= m[idx][i];
  }else
    for(; i >= 0; i--) cur[i] -= m[idx][i];
  return;
}

int main(int argc, char **argv){
  while(~scanf("%d %d\n", &M, &N)){
    ok = false;
    FILL(cur, 0);
    for(int i = 0; i < M; i++)
      for(int j = 0; j < N; j++)
	scanf("%d", &m[i][j]);
    
    dfs(0);

    if(ok) printf("Yes, I found it\n");
    else   printf("It is impossible\n");
  }
  return 0;
}
