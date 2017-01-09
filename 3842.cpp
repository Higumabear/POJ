// Time-stamp: <Mon Dec 12 21:56:09 東京 (標準時) 2016>
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


bool prime(int a){
  if(a < 2) return false;
  for(int i = 2; i * i <= a; i++)
    if(a % i == 0) return false;
  return true;
}
int main(int argc, char **argv){
  int N;
  cin >> N;
  while(N--){
    string s;
    cin >> s;
    sort(ALL(s));
    
    int ans = 0;
    map<int, bool> vis;
    do{
      int v = 0;
      for(int i = 0; i < s.size(); i++){
	v *= 10;
	v += (s[i] - '0');
	if(prime(v) && !vis.count(v)){
	  ans++;
	  vis[v] = true;
	}
      }
    }while(next_permutation(ALL(s)));
    cout << ans << endl;
  }
  return 0;
}
