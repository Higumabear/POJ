// Time-stamp: <Sat Jan 14 12:03:57 東京 (標準時) 2017>
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

// long double com(int p, int q, int r, int s){
//   long double ans = 1.0;
//   for(int i = 1; i <= 10000; i++){
//     if(i <= p) ans = ans * (long double)i;
//     //cout << ans << "\t";
//     if(i <= s) ans = ans * (long double)i;
//     //cout << ans << "\t";
//     if(i <= r - s) ans = ans * (long double)i;
//     //cout << ans << "\t";
//     if(i <= q) ans = ans / (long double)i;
//     //cout << ans << "\t";
//     if(i <= p - q) ans = ans / (long double)i;
//     //cout << ans << "\t";
//     if(i <= r) ans = ans / (long double)i;
//     printf("%lf\t", ans);
//   }
//   return ans;
// }

int main(int argc, char **argv){
  double p, q, r, s;
  while(scanf("%lf %lf %lf %lf", &p, &q, &r, &s) != EOF){
    priority_queue<int> nume, deno;
    for(int i = p; i >= 1; i--) nume.push(i);
    for(int i = s; i >= 1; i--) nume.push(i);
    for(int i = r - s; i >= 1; i--) nume.push(i);

    for(int i = q; i >= 1; i--) deno.push(i);
    for(int i = p - q; i >= 1; i--) deno.push(i);
    for(int i = r; i >= 1; i--) deno.push(i);

    double ans = (double)1.0;
    while(!nume.empty()){
      //cout << nume.top() << " " << deno.top() << " " << ans << endl;
      ans *= (double)nume.top();
      ans /= (double)deno.top();
      nume.pop(); deno.pop();
    }
    printf("%.5lf\n", ans);
  }
  return 0;
}
