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

int d[20];
int main(int argc, char **argv){
  int t, n;
  while(cin >> t >> n){
    if(t == 0 && n == 0) break;
    for(int i = 0; i < n; i++) cin >> d[i];

    sort(d, d + n);
    reverse(d, d + n);

    set<vector<int> > u;
    for(int S = 0; S < 1 << n; S++){
      int sum = 0;
      for(int i = 0; i < n; i++)
	if(S >> i & 1) sum += d[i];

      if(sum != t) continue;
      vector<int> num;
      for(int i = 0; i < n; i++)
	if(S >> i & 1) num.push_back(d[i]);
      u.insert(num);
    }
    cout << "Sums of " << t << ":" << endl;
    if(u.empty()) cout << "NONE" << endl;
    else
      for(set<vector<int> >::reverse_iterator it = u.rbegin();
	it != u.rend(); it++){
      for(int i = 0; i < (*it).size(); i++){
	cout << (*it)[i];
	if(i != (*it).size() - 1) cout << "+";
      }
      cout << endl;
    }
  }
}
