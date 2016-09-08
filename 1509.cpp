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

//abaaax
//
int main(int argc, char **argv){
  int N; cin >> N;
  while(N--){
    string s, t;
    cin >> s;
    int L = s.length();
    t = s;
    s += s;

    int idx = 0;
    for(int i = 1; i < L; i++){
      string tmp = s.substr(i, L);
      if(tmp < t){
	t = tmp;
	idx = i;
      }
    }
    cout << idx + 1 << endl;
    // char mac = 'a', mic = 'z';
    // for(int i = 0; i < L; i++){
    //   mac = max(mac, s[i]);
    //   mic = max(mic, s[i]);
    // }
    // if(mac == mic){
    //   cout << 1 << endl;
    //   continue;
    // }
    // vector<int> maidx, miidx;
    // for(int i = 0; i < L; i++){
    //   if(mac == s[i]) maidx.push_back(i);
    //   if(mic == s[i]) miidx.push_back(i);
    // }
  }
}
