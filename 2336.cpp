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
  int T;
  cin >> T;
  while(T--){
    int n, m, t;
    cin >> n >> t >> m;

    int leave[2000];
    int nf = (m + n - 1) / n;
    int k = m - (nf - 1) * n;
    for(int i = 0; i < k; i++) scanf("%d", leave);
    for(int f = 1; f < nf; f++)
      for(int i = 0; i < n; i++)
	scanf("%d", leave + f);
    for(int f = 0; f + 1 < nf; f++)
      if(leave[f] + 2 * t > leave[f + 1])
	leave[f + 1] = leave[f] + 2 * t;
    cout << leave[nf - 1] + t << " " << nf << endl;
  }
  return 0;
}
