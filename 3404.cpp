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

int main(){
  int N;
  cin >> N;
  int s[1000];
  for(int i = 0; i < N; i++)
    cin >> s[i];
  sort(s, s + N);

  int ans = 0;
  while(N > 3){
    int a = s[0] * 2 + s[N - 2] + s[N - 1];
    int b = s[0] + s[1] * 2 + s[N - 1];
    ans += min(a, b);
    N -= 2;
  }
  if(N == 3) ans += s[0] + s[1] + s[2];
  else ans += s[N - 1];
  cout << ans << endl;
  return 0;
}
