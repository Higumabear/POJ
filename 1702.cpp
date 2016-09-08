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

void pr(vector<int> a){
  for(int i = 0; i < a.size() - 1; i++)
    cout << a[i] << ",";
  cout << a.back();
}
int main(int argc, char **argv){
  int T; cin >> T;
  while(T--){
    int a; cin >> a;
    int p = 1;
    vector<int> l, r;
    while(a){
      if(a % 3 == 2){
	l.push_back(p);
	a++;
      }else if(a % 3 == 1){
	r.push_back(p);
      }
      p *= 3;
      a /= 3;
    }
    
    if(l.empty()) cout << "empty ";
    else{
      pr(l);
      cout << " ";
    }
    pr(r);
    cout << endl;
  }
}
