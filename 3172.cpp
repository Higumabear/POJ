// Time-stamp: <Fri Nov 10 03:10:48 太平洋標準時 2017>
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

int N;
ll C;
ll a[1001], b[1001];
ll ans = 0;

void dfs(int idx, ll sum){
  if(sum > C) return;
  ans = max(ans, sum);
  
  if(idx >= N) return;
  if(sum + b[idx] <= ans){
    //cout << idx << " " << sum << " " << sum + b[idx] << endl;
    return;
  }else
    dfs(idx + 1, sum);
  dfs(idx + 1, sum + a[idx]);
}

int main(int argc, char **argv){
  cin >> N >> C;
  for(int i = 0; i < N; i++) cin >> a[i];

  int k = (upper_bound(a, a + N, C) - a) - 1;
  k = N - 1 - k;

  reverse(a, a + N);
  b[N - 1] = a[N - 1];
  for(int i = N - 2; i >= 0; i--)
    b[i] = b[i + 1] + a[i];
  // for(int i = 0; i < N; i++)
  //   dump(b[i]);

  ans = a[k];
  //dump(ans);
  
  dfs(0, 0LL);
  cout << ans << endl;
  return 0;
}
