#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
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

int s[100001];
int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  while(N--){
    int a, S;
    scanf("%d %d", &a, &S);
    for(int i = 0; i < a; i++)
      scanf("%d", &s[i]);

    int sum = 0;
    int l = 0;
    int len = INF;
    for(int r = 0; r < a; r++){
      sum += s[r];
      while(sum >= S && r >= l){
	len = min(len, r - l + 1);
	sum -= s[l++];
      }
    }
    printf("%d\n", len == INF ? 0 : len);
  }
}
