// Time-stamp: <Mon Jan 09 20:36:09 東京 (標準時) 2017>
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

stack<int> st;
int main(int argc, char **argv){
  int n;
  ll ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int v;
    scanf("%d", &v);
    while(!st.empty() && st.top() <= v) st.pop();
    ans += st.size();
    st.push(v);
  }
  printf("%lld\n", ans);
  return 0;
}
