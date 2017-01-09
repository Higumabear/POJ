// Time-stamp: <Mon Jan 09 18:13:14 東京 (標準時) 2017>
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
  int n, m;
  cin >> n >> m;
  stack<int> history;
  set<int> state;
  state.insert(0);
  state.insert(n + 1);
  for(int i = 0; i < m; i++){
    char c; int d;
    scanf(" %c", &c);
    switch(c){
    case 'Q':
      scanf("%d", &d);
      if(state.count(d)) printf("0\n");
      else{
      // 	set<int>::iterator r, l;
      // 	r = upper_bound(ALL(state), d);
      // 	l = r;
      // 	l--;
      // 	printf("%d\n", *r - *l - 1);
	
	int l = 0, u = d;
	while(l + 1 < u){
	  int mid = (l + u) / 2;
	  if(*state.lower_bound(mid) > d) u = mid;
	  else l = mid;
	}
	printf("%d\n", *state.upper_bound(d) - l - 1);
      }
	
      break;
    case 'D':
      scanf("%d", &d);
      history.push(d);
      state.insert(d);

      //debug(state);
      break;
    default:
      int last = history.top();
      history.pop();
      state.erase(last);

      //debug(state);
    }
  }
  return 0;
}
