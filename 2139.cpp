#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
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

int d[301][301];

int main(int argc, char **argv){
  FILL(d, INF);
  for(int i = 0; i < 301; i++) d[i][i] = 0;

  int N, M;
  vector<int> a(1000);
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++){
    int T;
    scanf("%d", &T);
    for(int j = 0; j < T; j++){
      scanf("%d", &a[j]);
      a[j]--;
    }
    for(int p = 0; p < T; p++)
      for(int q = p + 1; q < T; q++)
	d[a[p]][a[q]] = d[a[q]][a[p]] = 1;
  }
  for(int k = 0; k < N; k++)
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


  int ans = INF;
  for(int i = 0; i < N; i++){
    int sum = 0;
    for(int j = 0; j < N; j++)
      sum += d[i][j];
    ans = min(ans, (int)(100.0 * sum / (N - 1)));
  }
  cout << ans << endl;
  return 0;
}
