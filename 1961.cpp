// Time-stamp: <Sat Feb 04 01:35:44 東京 (標準時) 2017>
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

vector<int> Z_algorithm(const string &s){
  vector<int> z(s.size(), 0);
  int l = 0, r = 0;
  for(int i = 1; i < s.size(); i++){
    if(z[i - l] <= r - i) z[i] = z[i - l];
    else{
      int k = max(0, r - i);
      while(i + k < s.size() && s[k] == s[i + k]) k++;
      z[i] = k;
      l = i, r = i + k - 1;
    }
  }
  return z;
}

bool use[1000110];
int main(int argc, char **argv){
  int N;
  string s;
  int idx = 1;
  while(cin >> N, N){
    cin >> s;
    fill(use, use + N + 100, false);
    vector<int> z = Z_algorithm(s);
    // for(int i = 0; i < N; i++)
    //   cout << s[i] << " ";
    // cout << endl;
    // for(int i = 0; i < N; i++)
    //   cout << z[i] << " ";
    // cout << endl;
    cout << "Test case #" << idx++ << endl;
    for(int i = 1; i <= N / 2; i++){
      int w = i;
      for(int k = 1; k * w <= z[i]; k++){
	if(!use[(k + 1) * w])
	  cout << (k + 1) * w << " " << k + 1 << endl;
	use[(k + 1) * w] = true;
      }
    }
    cout << endl;
  }
  return 0;
}
