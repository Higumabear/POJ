// Time-stamp: <Sat Jan 28 17:02:08 東京 (標準時) 2017>
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
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int u;
    cin >> u;
    u = min(u, 9);

    int N = 2 * u + 1;
    cout << "Scenario #" << t << ":" << endl;
    for(int z = 0; z < N; z++){
      cout << "slice #" << z + 1 << ":" << endl;
      for(int x = 0; x < N; x++){
	for(int y = 0; y < N; y++){
	  int d = abs(x - u) + abs(y - u) + abs(z - u);
	  if(d <= u) cout << d;
	  else cout << '.';
	}
	cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
