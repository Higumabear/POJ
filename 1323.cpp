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
  int N, M, round = 0;
  while(cin >> N >> M, N + M){
    round++;
    vector<int> mine, others;
    for(int i = 0; i < M; i++){
      int a;
      cin >> a;
      mine.push_back(a);
    }
    sort(mine.rbegin(), mine.rend());

    for(int i = N * M; i >= 0; i--)
      if(count(ALL(mine), i) == 0)
	others.push_back(i);

    int cnt = 0, opp = 0;
    for(int i = 0; i < M; i++){
      if(mine[i] > others[opp])
	cnt++;
      else
	opp++;
    }
    cout << "Case " << round << ": " << cnt << endl;
  }
  return 0;
}