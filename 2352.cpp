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

template <class T>
struct BIT{
  int N;
  vector<T> dat;
  T sum(int i){ // return sum [0, i)
    i--;
    T s = 0;
    while(i > 0){
      s += dat[i];
      i -= i & -i;
    }
    return s;
  }
public:
  BIT(int sz) : N(sz) { dat.assign(2 * sz + 2, 0); }
  T sum(int l, int r){ // return sum [l, r)
    return sum(r + 1) - sum(l);
  }
  void add(int i, T x){
    while(i <= N){
      dat[i] += x;
      i += i & -i;
    }
  }
};

int cnt[33000], check_cnt[33000];
int x[33000], y[33000];

int main(){
  int N;
  scanf("%d", &N);

  BIT<int> bit(33000);
  const int OFFSET = 100;
  for(int i = 0; i < N; i++){
    scanf("%d %d", x + i, y + i);
    cnt[bit.sum(x[i] + OFFSET + 1)]++;
    bit.add(x[i] + OFFSET, 1);
  }

  // for(int i = 0; i < N; i++){
  //   int s = 0;
  //   for(int j = 0; j < i; j++)
  //     if(x[j] <= x[i]) s++;
  //   check_cnt[s]++;
  // }
  
  for(int i = 0; i < N; i++){
    printf("%d\n", cnt[i]);
    //printf("%d %d\n", cnt[i], check_cnt[i]);
  }
  return 0;
}
