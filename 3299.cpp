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

int main(int argc, char **argv){
  char a, b;
  double u, v;
  while(cin >> a){
    if(a == 'E') break;
    cin >> u >> b >> v;
    map<char, double> f;
    f[a] = u, f[b] = v;
    
    if(!f.count('T')){
      double D = f['D'], H = f['H'];
      double e = 6.11 * exp(5417.753 / 273.16 - 5417.753 / (D + 273.16));
      double h = 0.5555 * (e - 10.0);
      double T = H - h;
      printf("T %.1f D %.1f H %.1f\n", T, D, H);
    }else if(!f.count('D')){
      double T = f['T'], H = f['H'];
      double h = H - T;
      double e = 10.0 + h / 0.5555;
      double tmp = log(e / 6.11) / 5417.753;
      double D = 273.16 / (1.0 - 273.16 * tmp) - 273.16;
      printf("T %.1f D %.1f H %.1f\n", T, D, H);
    }else{
      double T = f['T'], D = f['D'];
      double e = 6.11 * exp(5417.753 / 273.16 - 5417.753 / (D + 273.16));
      double h = 0.5555 * (e - 10.0);
      double H = T + h;      
      printf("T %.1f D %.1f H %.1f\n", T, D, H);
    }
  }
  return 0;
}
