// Time-stamp: <Mon Aug 08 21:29:35 東京 (標準時) 2016>
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

int N, cnt;
char op[20];

void rec(int idx, int sum, int cur, int tmp){
  if(idx == N - 1){
    if(sum + cur * tmp == 0){
      cnt++;
      if(cnt > 20) return;
      for(int i = 0; i < N - 1; i++) 
    	cout << i + 1 << " " << op[i] << " ";
      cout << N << endl;
    }
    return;
  }
  op[idx] = '+';
  rec(idx + 1, sum + cur * tmp, idx + 2, 1);
  op[idx] = '-';
  rec(idx + 1, sum + cur * tmp, idx + 2, -1);
  op[idx] = '.';
  if(idx < 8)
    rec(idx + 1, sum, cur * 10 + idx + 2, tmp);
  else
    rec(idx + 1, sum, cur * 100 + idx + 2, tmp);
  return;
}
int main(int argc, char **argv){
  cin >> N;
  cnt = 0;
  rec(0, 0, 1, 1);
  cout << cnt << endl;
  return 0;
}
