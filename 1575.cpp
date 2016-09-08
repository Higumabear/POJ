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
  string s;
  while(cin >> s){
    if(s == "end") break;  
    
    int L = s.length();
    bool vowel = false;
    bool ok = true;
    int cv = 0, cc = 0;
    for(int i = 0; i < L; i++){
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
	 s[i] == 'o' || s[i] == 'u'){
	cv++;
	cc = 0;
	vowel = true;
      }else{
	cc++;
	cv = 0;
      }
      if(cv >= 3 || cc >= 3) ok = false;
      if(i > 0 && s[i - 1] == s[i] && 
	 s[i] != 'e' && s[i] != 'o')ok = false;
    }
    ok &= vowel;
    cout << "<" << s << "> is " << 
      (ok ? "acceptable.": "not acceptable.") << endl;
  }
  return 0;
}
