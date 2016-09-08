#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
#define INF 1 << 25
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);

int d[105][105];

int main(int argc, char **argv){
  int N;
  cin >> N;
  FILL(d, INF);
  
  string c;
  for(int i = 0; i < N - 1; i++){
    for(int j = 0; j <= i; j++){
      cin >> c;
      if(c == "x") continue;
      d[j][i + 1] = d[i + 1][j] = s2i(c);
    }
  }
  for(int i = 0; i < N; i++) d[i][i] = 0;

  // for(int i = 0; i < N; i++){
  //   for(int j = 0; j < N; j++){
  //     cout << d[i][j] << " ";
  //   }
  //   cout << endl;
  // }	
  
  for(int k = 0; k < N; k++)
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  cout << *max_element(d[0], d[0] + N) << endl;
  return 0;
}
