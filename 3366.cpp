#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
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
  int N, M;
  cin >> N >> M;

  map<string, string> ir;
  for(int i = 0; i < N; i++){
    string s, t;
    cin >> s >> t;
    ir[s] = t;
  }

  for(int i = 0; i < M; i++){
    string s;
    cin >> s;
    string t("#" + s);
    
    if(ir.count(s)) cout << ir[s] << endl;
    else{
      t = t.substr(t.length() - 2);
      if(t[1] == 'y' && !(t[0] == 'a' || t[0] == 'e' ||
			  t[0] == 'i' || t[0] == 'o' || t[0] == 'u'))
	cout << s.substr(0, s.length() - 1) + "ies" << endl;
      else if(t[1] == 'o' || t[1] == 's' || t == "ch" ||
	      t == "sh" || t[1] == 'x')
	cout << s + "es" << endl;
      else
	cout << s + "s" << endl;
    }
  }
  return 0;
}
