// Time-stamp: <Sun Jan 29 17:13:35 東京 (標準時) 2017>
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

int d[3100];
bool ludic[35000];
int main(int argc, char **argv){
  FILL(ludic, true);
  ludic[0] = ludic[1] = false;
  for(int i = 2; i < 35000; i++){
    if(!ludic[i]) continue;
    int j = i + 1;
    int cnt = 0;
    while(j < 35000){
      if(ludic[j]) cnt++;
      if(cnt % i == 0) ludic[j] = false;
      j += 1;
    }
  }
  
  int j = 0;
  for(int i = 0; i < 35000; i++)
    if(ludic[i]) d[j++] = i;
  
  int idx;
  while(cin >> idx, idx) cout << d[idx - 1] << endl;
  return 0;
}
