// Time-stamp: <Thu Mar 09 22:59:38 東京 (標準時) 2017>
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
#define EPS 1e-9
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(int argc, char **argv){
  int N, D, idx = 0;
  while(cin >> N >> D, N + D){
    bool reach = true;
    vector<pair<int, int> > p(N);
    for(int i = 0; i < N; i++){
      cin >> p[i].first >> p[i].second;
      if(p[i].second > D) reach = false;
    }
    if(!reach){
      cout << "Case " << ++idx << ": " << -1 << endl;
      continue;
    }

    sort(ALL(p));

    int ans = 0;
    int x = p[0].first, y = p[0].second;
    for(int i = 1; i < N;){
      double r = x + sqrt(D * D - y * y);
      if(r >= p[i].first - sqrt(D * D - p[i].second * p[i].second)){
	if(r > p[i].first + sqrt(D * D - p[i].second * p[i].second)){
	  x = p[i].first, y = p[i].second;
	}
      }else{
	ans++;
	x = p[i].first, y = p[i].second;
      }
      i++;
    }
    cout << "Case " << ++idx << ": " << ans + 1 << endl;
  }
  return 0;
}
