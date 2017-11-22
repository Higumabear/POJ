// Time-stamp: <Mon Feb 20 21:57:27 東京 (標準時) 2017>
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

int d[100][100];
int main(int argc, char **argv){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> d[i][j];
  
  vector<int> cnt(m, 0);
  vector<bool> f(m, true);

  for(int i = 0; i < n; i++){
    int mav = *max_element(d[i], d[i] + m);
    int miv = *min_element(d[i], d[i] + m);
    for(int j = 0; j < m; j++){
      if(d[i][j] == mav) f[j] = false;
      if(d[i][j] == miv) cnt[j]++;
    }
  }
  vector<int> ans;
  for(int j = 0; j < m; j++)
    if(cnt[j] >= (n + 1) / 2 && f[j]) ans.push_back(j); 
  
  if(ans.empty()){
    cout << 0 << endl;
  }else{
    for(int i = 0; i < ans.size(); i++)
      cout << ans[i] + 1 << " ";
    cout << endl;
  }
  return 0;
}
