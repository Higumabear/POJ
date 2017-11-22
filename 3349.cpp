// Time-stamp: <Sat Feb 18 01:25:26 東京 (標準時) 2017>
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

inline vector<unsigned int> minperm(vector<unsigned int> &m){
  vector<unsigned int> ret = m;
  for(unsigned int k = 0; k < 2; k++){
    for(unsigned int i = 0; i < 6; i++){
      rotate(m.begin(), m.begin() + 1, m.end());
      if(ret > m) ret = m;
    }
    reverse(ALL(m));
  }
  return ret;
}

inline unsigned int myhash(vector<unsigned int> &v, unsigned int MOD){
  unsigned int b = 1, hash = 0;
  for(unsigned int i = 0; i < 6; i++){
    hash += b * (unsigned int)v[i];
    b *= MOD;
  }
  return hash;
}

const int HS = 1 << 22;
const int mask = HS - 1;
unsigned int ht[HS];

int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  vector<unsigned int> t(6);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < 6; j++) scanf("%u", &t[j]);
    t = minperm(t);
    unsigned int h1 = myhash(t, 1000000007) & mask;
    unsigned int h2 = myhash(t, 999999997);
    if(!h2) h2 = 1 << 30;
    if(!ht[h1]) ht[h1] = h2;
    else if(ht[h1] == h2){
      printf("Twin snowflakes found.\n");
      return 0;
    }
  }
  printf("No two snowflakes are alike.\n");
  return 0;
}