// Time-stamp: <Sun Feb 26 13:46:01 東京 (標準時) 2017>
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

int m, k;
vector<ll> page;

int C(ll v){
  ll sum = 0;
  int cnt = 0;
  for(int i = m - 1; i >= 0; i--){
    if(v < page[i]) return INF;
    if(sum + page[i] <= v){
      sum += page[i];
    }else{
      cnt++;
      sum = page[i];
    }
  }
  return cnt;
}

int main(int argc, char **argv){
  int n;
  cin >> n;
  while(n--){
    cin >> m >> k;
    page.resize(m);

    ll ub = 0LL, lb = 0LL, div;
    for(int i = 0; i < m; i++){ 
      cin >> page[i];
      ub += page[i];
    }
    
    while(lb < ub){
      ll mid = (ub + lb) / 2;
      div = C(mid);
      if(div + 1 <= k) ub = mid;
      else lb = mid + 1;
    }
    reverse(ALL(page));
    ll sum = 0, rem = k - C(ub) - 1;
    vector<int> a;
    //cout << ub << " " << C(ub) << endl;
    for(int i = 0; i < page.size(); i++){
      if(sum + page[i] > ub){
	sum = 0;
	a.push_back(-1);
      }
      sum += page[i];
      a.push_back(page[i]);
    }
    reverse(ALL(a));
    vector<int> b;
    for(int i = 0; i < a.size(); i++){
      b.push_back(a[i]);
      if(i < a.size() - 1){
	if(rem && (a[i] != -1 && a[i + 1] != -1)){
	  rem--;
	  b.push_back(-1);
	}
      }
    }
    for(int i = 0; i < b.size(); i++)
      if(b[i] == -1) cout << "/ ";
      else cout << b[i] << " ";
    cout << endl;
  }
  return 0;
}
