// Time-stamp: <Fri Mar 10 18:50:19 東京 (標準時) 2017>
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

int d[20001], h[200001];

int main(int argc, char **argv){
  int N, M;
  while(cin >> N >> M, N + M){
    vector<int> d(N), h(M);
    for(int i = 0; i < N; i++) cin >> d[i];
    for(int i = 0; i < M; i++) cin >> h[i];
    sort(ALL(d)), sort(ALL(h));
    
    int i = 0, j = 0, ans = 0;
    while(i < N){
      if(j == M){
	cout << "Loowater is doomed!" << endl;
	goto L1;
      }
      if(d[i] <= h[j]){
	ans += h[j];
	i++, j++;
      }else{
	j++;
      }
    }
    cout << ans << endl;
  L1:;
  }
  return 0;
}
