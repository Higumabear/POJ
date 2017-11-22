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

int argmax(vector<int> &a){
  int idx = 0;
  for(int i = 0; i < a.size(); i++)
    if(abs(a[idx]) < abs(a[i]))
      idx = i;
  return idx;
}

int main(){
  int T;
  cin >> T;
  while(T--){
    int N, M;
    cin >> N >> M;
    vector<int> a;
    int f;
    for(int i = 0; i < N; i++){
      cin >> f;
      a.push_back(f);
    }

    a[M] *= -1;
    
    int ans = 0;
    while(1){
      int idx = argmax(a);
      rotate(a.begin(), a.begin() + idx, a.end());

      if(a[0] < 0) {
	cout << ans + 1 << endl;
	break;
      }

      // for(int i = 0; i < a.size(); i++)
      // 	cout << a[i] << " ";
      // cout << endl;
      a.erase(a.begin());
      ans++;
    }
  }
  return 0;
}
