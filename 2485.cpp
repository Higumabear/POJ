#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);

int uf[1000];
int find(int x){
  return uf[x] == x ? x : uf[x] = find(uf[x]);
}
int unite(int a, int b){
  return uf[find(a)] = uf[find(b)] = find(a);
}

int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  for(int k = 0; k < T; k++){
    int N;
    scanf("%d", &N);
    vector<pair<int, pair<int, int> > > path;
    for(int i = 0; i < N; i++){
      uf[i] = i;
      for(int j = 0; j < N; j++){
	int d;
	scanf("%d", &d);
	if(i < j) 
	  path.push_back(make_pair(d, make_pair(i, j)));
      }
    }
    sort(ALL(path));

    int ans = 0;
    for(int i = 0; i < path.size(); i++){
      int l = path[i].first, from = path[i].second.first, 
	to = path[i].second.second;
      if(find(to) == find(from)) continue;
      unite(from, to);
      ans = l;
    }
    printf("%d\n", ans);
  }
  return 0;
}