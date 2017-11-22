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
  int N, idx = 0;
  while(cin >> N, N){
    vector<vector<double> > d(N, vector<double>(N, 0));
    map<string, int> enc;
    for(int i = 0; i < N; i++){
      string s; cin >> s;
      enc[s] = i;
    }
    int T; cin >> T;
    for(int i = 0; i < T; i++){
      string s, t;
      double rate;
      cin >> s >> rate >> t;
      rate = log(rate);
      d[enc[s]][enc[t]] = rate;
    }
    for(int k = 0; k < N; k++)
      for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	  d[i][j] = max(d[i][j], d[i][k] + d[k][j]);

    bool flag = false;
    for(int i = 0; i < N; i++)
      if(exp(d[i][i]) > 1.0 + EPS) flag = true;
    cout << "Case " << ++idx << ": "
	 << (flag ? "Yes" : "No") << endl;
  }
  return 0;
}