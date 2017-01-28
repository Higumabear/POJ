// Time-stamp: <Sat Jan 28 16:09:56 東京 (標準時) 2017>
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

int d[300000];
bool on[300000];
int main(int argc, char **argv){
  int n, m, c, t = 0;
  while(cin >> n >> m >> c){
    if(n == 0 && m == 0 && c == 0) break;
    FILL(on, false);
    for(int i = 0; i < n; i++) 
      cin >> d[i];

    bool check = false;
    int consum = 0, maxuse = 0;
    for(int i = 0; i < m; i++){
      int idx; cin >> idx;
      idx--;
      consum += (!on[idx] ? d[idx] : -d[idx]);
      on[idx] = !on[idx];
      maxuse = max(maxuse, consum);
      if(c < consum) 
	check = true;
    }
    printf("Sequence %d\n", ++t);
    if(check) printf("Fuse was blown.\n\n");
    else{
      printf("Fuse was not blown.\n");
      printf("Maximal power consumption was %d amperes.\n\n", maxuse);
    }
  }
  return 0;
}
