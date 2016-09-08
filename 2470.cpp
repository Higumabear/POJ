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
  int n;
  while(1){
    scanf("%d", &n);
    if(n == 0) break;

    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
      int a; scanf("%d", &a);
      v[i] = a - 1;
    }
    bool ok = true;
    for(int i = 0; i < n; i++)
      if(v[v[i]] != i) ok = false;

    printf("%s\n", ok ? "ambiguous" : "not ambiguous");
  }
  return 0;
}