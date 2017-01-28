// Time-stamp: <Thu Jan 19 23:34:15 東京 (標準時) 2017>
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

//bool r[1000001];
int d[301];
int main(int argc, char **argv){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", d + i);
    
    int i;
    for(i = 1; ; i++){
      //FILL(r, false);
      vector<bool> r(i, false);
      bool check = true;
      for(int j = 0; j < n; j++){
	if(r[d[j] % i]){
	  check = false;
	  break;
	}else{
	  r[d[j] % i] = true;
	}
      }
      if(check) break;
    }
    printf("%d\n", i);
  }
  return 0;
}