// Time-stamp: <Sun Feb 05 12:41:03 東京 (標準時) 2017>
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
#include <complex>

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

double add(double a, double b){
  if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}

struct P{
  double x, y;
  P() {}
  P(double x, double y) : x(x), y(y) {}
  P operator + (P p){
    return P(add(x, p.x), add(y, p.y));
  }
  P operator - (P p){
    return P(add(x, -p.x), add(y, -p.y));
  }
  P operator * (double d){
    return P(x * d, y * d);
  }
  double dot(P p){
    return add(x * p.x, y * p.y);
  }
  double det(P p){
    return add(x * p.y, -y * p.x);
  }
};

bool cmp_x(P a, P b){
  if(a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

vector<P> convex_hull(vector<P> &p){
  int N = p.size();
  sort(p.begin(), p.end(), cmp_x);
  int k = 0;
  vector<P> ret(N * 2);
  for(int i = 0; i < N; i++){
    while(k > 1 && (ret[k - 1] - ret[k - 2]).det(p[i] - ret[k - 1]) <= 0) k--;
    ret[k++] = p[i];
  }
  for(int i = N - 2, t = k; i >= 0; i--){
    while(k > t && (ret[k - 1] - ret[k - 2]).det(p[i] - ret[k - 1]) <= 0) k--;
    ret[k++] = p[i];
  }
  ret.resize(k - 1);
  return ret;
}

int main(int argc, char **argv){
  int N;
  vector<P> p;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    P tmp;
    scanf("%lf %lf", &tmp.x, &tmp.y);
    p.push_back(tmp);
  }
  double ans = 0;
  vector<P> ch = convex_hull(p);
  for(int i = 0; i < ch.size(); i++){
    for(int j = 0; j < i; j++){
      ans = max(ans, (ch[i] - ch[j]).dot(ch[i] - ch[j]));
    }
  }
  printf("%.0f\n", ans);
  return 0;
}
