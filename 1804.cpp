// Time-stamp: <Wed Jun 15 03:12:19 東京 (標準時) 2016>
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

using namespace std;

int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  for(int k = 0; k < T; k++){
    int N;
    scanf("%d", &N);
    vector<int> a(N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    
    int cnt = 0;
    vector<int> b = a;
    sort(ALL(b));
    for(int i = 0; i < N; i++){
      int idx;
      for(idx = i; idx < N; idx++) if(b[i] == a[idx]) break;
      for(int j = idx; j > i; j--){
	swap(a[j], a[j - 1]);
	cnt++;
      }
    }
    printf("Scenario #%d:\n%d\n\n", k + 1, cnt);
  }
  return 0;
}
