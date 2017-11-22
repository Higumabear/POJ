// Time-stamp: <Thu Mar 23 23:47:37 東京 (標準時) 2017>
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

vector<int> e[10010];

int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  while(T--){
    for(int i = 0; i < 10010; i++)
      e[i].clear();

    int M;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
      int x, y;
      scanf("%d %d", &x, &y);
      e[x].push_back(y);
    }
    multiset<int> S;
    for(int i = 0; i < 10010; i++){
      for(int j = 0; j < e[i].size(); j++){
	if(S.empty()) continue;
	multiset<int>::iterator it = S.lower_bound(e[i][j]);
	if(it == S.begin()) continue;
	S.erase(--it);
      }
      for(int j = 0; j < e[i].size(); j++)
	S.insert(e[i][j]);
    }
    printf("%d\n", S.size());
  }
  return 0;
}
