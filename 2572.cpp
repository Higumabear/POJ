#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

int main(){
  string s;
  while(1){
    cin >> s;
    int L = s.length();
    for(int i = 0; i< L; i++) if(!isdigit(s[i])) s[i] = ' ';
    string a, b, c;
    stringstream ss(s);
    ss >> a >> b >> c;
    reverse(ALL(a));    reverse(ALL(b));    reverse(ALL(c));
    int da = s2i(a);
    int db = s2i(b);
    int dc = s2i(c);

    cout << ((da + db == dc) ? "True" : "False") << endl;
    if(da == 0 && db == 0 && dc == 0) break;
  }
  return 0;
}