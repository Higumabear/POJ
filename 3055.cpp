// Time-stamp: <Wed Jan 18 00:33:22 東京 (標準時) 2017>
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

int smag[256], tmag[256];
bool check(){
  for(int i = 0; i < 256; i++)
    if((smag[i] && !tmag[i]) || (!smag[i] && tmag[i]))
      return false;
  return true;
}

bool singleex(string s, string t){
  FILL(smag, 0);
  FILL(tmag, 0);  
  for(int i = 0; i < s.size(); i++) smag[s[i]]++;
  for(int i = 0; i < t.size(); i++) tmag[t[i]]++;

  bool good = false;
  for(int i = 0; i < t.size() - 1; i++){
    char c1 = t[i], c2 = t[i + 1];
    if(c1 < '9' && c2 > '0'){
      tmag[c1]--, tmag[c2]--;
      tmag[c1 + 1]++, tmag[c2 - 1]++;
      good |= check();
      tmag[c1 + 1]--, tmag[c2 - 1]--;
      tmag[c1]++, tmag[c2]++;
    }
    if(c1 > '0' && c2 < '9'){
      if(i == 0 && c1 == '1') continue;
      tmag[c1]--, tmag[c2]--;
      tmag[c1 - 1]++, tmag[c2 + 1]++;
      good |= check();
      tmag[c1 - 1]--, tmag[c2 + 1]--;
      tmag[c1]++, tmag[c2]++;
    }    
  }
  return good;
}


int main(int argc, char **argv){
  int n;
  cin >> n;
  while(n--){
    string s, t;
    cin >> s >> t;

    FILL(smag, 0);
    FILL(tmag, 0);  
    for(int i = 0; i < s.size(); i++) smag[s[i]]++;
    for(int i = 0; i < t.size(); i++) tmag[t[i]]++;
    
    if(check()){
      cout << "friends" << endl;
      continue;
    }
    if(singleex(s, t) || singleex(t, s)){
      cout << "almost friends" << endl;
      continue;
    }
    cout << "nothing" << endl;
  }
  return 0;
}
