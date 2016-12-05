// Time-stamp: <Sun Nov 13 20:53:34 東京 (標準時) 2016>
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
  char tree[256];
  map<string, int> p;
  int num = 0;
  while(gets(tree)){
    p[string(tree)]++;
    num++;
  }
  map<string, int>::iterator it = p.begin();
  for(; it != p.end(); it++){
    printf("%s %.4f\n", (it->first).c_str(), it->second * 100.0 / num);
  }
  return 0;
}
