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


int main(int argc, char **argv){
  string s, t;
  while(cin >> s){
    t += s;
    t += " ";
  }
  stringstream ss(t);

  int num = 0;
  while(ss >> s){
    if(s == "<br>"){
      cout << endl;
      num = 0;
    }else if(s == "<hr>"){
      if(num) cout << endl;
      cout << string(80, '-') << endl;
      num = 0;
    }else{
      if(num){
	if(num + 1 + s.size() <= 80){
	  cout << " " << s;
	  num += 1 + s.size();
	}else{
	  cout << endl << s;
	  num = s.size();
	}
      }else{
	cout << s;
	num = s.size();
      }
    }
  }
  return 0;
}