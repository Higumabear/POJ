#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);


int main(int argc, char **argv){
  int N, D, K;
  cin >> N >> D >> K;

  vector<int> have[N];
  for(int i = 0; i < N; i++){
    int d; cin >> d;
    for(int j = 0; j < d; j++){
      int virus; cin >> virus;
      have[i].push_back(virus - 1);
    }
  }
  int ans = 0;
  for(int S = 0; S < 1 << D; S++){
    if(__builtin_popcount(S) > K) continue;
    int cnt = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < have[i].size(); j++){
	if(!(S >> have[i][j] & 1))
	  goto L1;
      }
      cnt++;
    L1:;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
