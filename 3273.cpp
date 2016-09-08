// Time-stamp: <Thu Aug 11 22:36:27 東京 (標準時) 2016>
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

vector<int> p;
bool C(ll v, ll M){
  int N = p.size();

  ll sum = 0, cnt = 1;
  for(int i = 0; i < N; i++){
    if(sum + p[i] <= v){
      sum += p[i];
    }else{
      sum = p[i];
      cnt++;
    }
  }
  return cnt > M;
}
int main(int argc, char **argv){
  int N, M;
  scanf("%d %d", &N, &M);
  p.resize(N);
  for(int i = 0; i < N; i++)
    scanf("%d", &p[i]);

  ll lb = *max_element(ALL(p)); 
  ll ub = accumulate(ALL(p), 0);
  while(ub - lb > 0){
    ll mid = (lb + ub) / 2;
    if(C(mid, M)) lb = mid + 1;
    else ub = mid;
  }
  cout << lb << endl;
  return 0;
}
