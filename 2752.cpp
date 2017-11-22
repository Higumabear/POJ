// Time-stamp: <Wed Feb 01 21:43:54 東京 (標準時) 2017>
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
  z[0] = s.size();
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

vector<int> b(const string &S){
  vector<int> A(S.size() + 1, 0);
  A[0] = -1;
  int j = -1;
  for (int i = 0; i < S.size(); i++) {
    while (j >= 0 && S[i] != S[j]) j = A[j];
    j++;
    A[i+1] = j;
  }
  return A;
}

int main(int argc, char **argv){
  string s;
  while(cin >> s){
    vector<int> a = Z_algorithm(s);
    //vector<int> a = b(s);
    
    //sort(ALL(a));
    //a.erase(unique(ALL(a)), a.end());
    for(int i = a.size() - 1; i >= 0; i--){
      if(a[i] > 0 && i + a[i] == s.size()) cout << a[i] << " ";
    }
      //if(a[i] != 0) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}