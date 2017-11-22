// Time-stamp: <Mon Apr 17 23:34:33 東京 (標準時) 2017>
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
  int P;
  scanf("%d", &P);
  while(P--){
    int c, M;
    scanf("%d %d", &c, &M);

    printf("%d %d\n", c, (M + 1) / 2);

    int a;
    multiset<int> r;
    for(int i = 0; i < M; i++){
      scanf("%d", &a);
      r.insert(a);
      if(i % 2 == 0){
	set<int>::iterator it = r.begin();
	advance(it, i / 2);
	printf("%d ", *(it));
	//dump((*it));
      }
      if((i + 1) % 20 == 0 && i != M - 1) puts("");
    }
    puts("");
  }
  
  return 0;
}
