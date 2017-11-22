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

int p,n,e[400][400];
int pr[400];
bool V[400];

bool rec(int s)
{
  if(s<0)return 1;
  for(int i=s<p?p:0;i<(s<p?p+n:p);i++)if(!V[i]&&e[s][i]){
    V[i]=1;
    if(rec(pr[i]))return pr[i]=s,pr[s]=i,1;
  }
  return 0;
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int C, x;
    scanf("%d %d", &p, &n);

    memset(e, 0, sizeof(e));
    memset(pr, -1, sizeof(pr));

    for(int i = 0; i < p; i++){
      scanf("%d", &C);
      for(int j = 0; j < C; j++){
    	scanf("%d", &x);
	e[i][p + x - 1] = e[p + x - 1][i] = 1;
      }
    }

    int cnt = 0;
    for(int i = 0; i < p; i++){
      fill(V, V + p + n, 0);
      V[i] = 1;
      if(rec(i)) cnt++;
    }
    // dump(P);
    // dump(N);
    //dump(cnt);
    puts(cnt == p ? "YES" : "NO");
  }
  return 0;
}
