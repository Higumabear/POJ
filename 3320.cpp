// Time-stamp: <Tue Dec 06 22:19:30 東京 (標準時) 2016>
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

int p[1001001], knowledge[1001001];
int main(int argc, char **argv){
  map<int, int> v;
  int P, idx = 0, K = 0;
  scanf("%d", &P);
  for(int i = 0; i < P; i++){
    int t;
    scanf("%d", &t);
    if(!v.count(t)) v[t] = K++;
    p[i] = v[t];
  }
  // dump(K);
  // for(int i = 0; i < P; i++)
  //   cout << p[i] << " ";
  // cout << endl;

  int l = 0, r = 0;
  int get = 0, ans = INF;
  while(l <= r){
    if(get < K && r < P){
      if(knowledge[p[r]] == 0) get++;
      knowledge[p[r]]++;
      r++;
    }else{
      if(knowledge[p[l]] == 1) get--;
      knowledge[p[l]]--;
      l++;
    }
    if(get >= K) ans = min(ans, r - l);
  }
  printf("%d\n", ans);
  return 0;
}
