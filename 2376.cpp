// Time-stamp: <Fri Mar 24 22:05:32 東京 (標準時) 2017>
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

pair<int, int> e[26000];

int main(int argc, char **argv){
  int N, T;
  scanf("%d %d", &N, &T);
  for(int i = 0; i < N; i++)
    scanf("%d %d", &e[i].first, &e[i].second);
  e[N].first = -INF, e[N].second = 0;  
  //e[N + 1].first = T, e[N + 1].second = INF;
  N++;
  sort(e, e + N);

  int end = 0, ans = 0;
  for(int i = 0; i < N; ){
    if(end >= T && ans) break;
    
    int next = -1, maxreach = end;
    for(int j = i + 1; j < N; j++){
      if(e[j].first <= end + 1){
	if(maxreach <= e[j].second){
	  maxreach = e[j].second;
	  next = j;
	}
      }else break;
    }
    if(next == -1) break;
    
    //dump(maxreach);
    i = next;
    end = maxreach;
    ans++;
  }
  printf("%d\n", end < T ? -1 : ans);
  return 0;
}
