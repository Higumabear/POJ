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

int d[] = {9, 3, 7};

int main(int argc, char **argv){
  int N; cin >> N;
  for(int i = 1; i <= N; i++){
    string s;
    cin >> s;
    reverse(ALL(s));

    int checksum = 0;
    int pos = -1;
    for(int j = 0; j < s.length(); j++){
      if(s[j] == '?') pos = j;
      else checksum += ((s[j] - '0') * d[j % 3]);
    }
    for(int j = 0; j < 10; j++){
      if((checksum + d[pos % 3] * j) % 10 == 0){
	s[pos] = (char)(j + '0');
	break;
      }
    }
    reverse(ALL(s));
    cout << "Scenario #" << i << ":" << endl
	 << s << endl << endl;
  }
}
