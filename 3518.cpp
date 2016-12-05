// Time-stamp: <Fri Nov 11 21:19:55 東京 (標準時) 2016>
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

bool pr[1300100];
int main(int argc, char **argv){
  FILL(pr, true);
  pr[1] = false;
  for(int i = 2; i * i < 1300100; i++){
    if(!pr[i]) continue;
    for(int j = 2 * i; j < 1300100; j += i) pr[j] = false;
  }
  vector<int> p;
  for(int i = 0; i < 1300100; i++)
    if(pr[i]) p.push_back(i);

  int k;
  while(cin >> k, k){
    for(int i = 0; i < p.size(); i++){
      if(p[i] == k){
	cout << 0 << endl;
	break;
      }
      if(p[i] < k && k < p[i + 1]){
	cout << p[i + 1] - p[i] << endl;
	break;
      }
    }
  }
  return 0;
}
