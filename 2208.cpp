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

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(){
  double ab, ac, ad, bc, bd, cd;
  while(cin >> ab >> ac >> ad >> bc >> bd >> cd){
    double a = (ad*ad+bd*bd-ab*ab) / (2 * ad*bd);
    double b = (cd*cd+bd*bd-bc*bc) / (2 * cd*bd);
    double c = (ad*ad+cd*cd-ac*ac) / (2 * ad*cd);
    double V = 1/6.0 * ad * bd * cd * sqrt(1 + 2*a*b*c - a*a - b*b - c*c);
    printf("%.4lf\n", V);
  }
  return 0;
}
