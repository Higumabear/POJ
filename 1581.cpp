// Time-stamp: <Sun Aug 07 19:50:58 東京 (標準時) 2016>
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

string team[1001];
int solved[1001], penalty[1001];
int main(int argc, char **argv){
  int N;
  cin >> N;
  FILL(solved, 0);
  FILL(penalty, 0);
    
  for(int i = 0; i < N; i++){
    cin >> team[i];
    
    int a, b;
    for(int j = 0; j < 4; j++){
      cin >> a >> b;
      if(b == 0) continue;
      solved[i]++;
      penalty[i] += ((a - 1) * 20 + b);
    }
  }
  int idx = -1, minpen = INF;
  int maxsolved = *max_element(solved, solved + 1001);
  for(int i = 0; i < N; i++){
    if(solved[i] != maxsolved) continue;
    if(penalty[i] < minpen){
      idx = i;
      minpen = penalty[i];
    }
  }
  cout << team[idx] << " " << maxsolved << " " << minpen << endl;
  return 0;
}
