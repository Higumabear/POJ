#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#define ALL(c) (c).begin(), (c).end()

using namespace std;
static const double EPS = 1e-8;
static const int INF = 1 << 29;
typedef long long ll;

int main(){
  string s, t;
  while(cin >> t) s += (t + " ");

  string a;
  map<string, int> occ;
  for(int i = 0; i < (int)s.length(); i++){
    if(isalpha(s[i])) a += tolower(s[i]);
    else{
      if(!a.empty()) occ[a]++;
      a = "";
    }
  }

  vector<string> freq;
  int cnt = 0;
  for(map<string, int>::iterator it = occ.begin(); it != occ.end();
      it++){
    if(it -> second > cnt){
      cnt = it -> second;
      freq.clear();
      freq.push_back(it -> first);
    }else if(it -> second == cnt)
      freq.push_back(it -> first);
  }

  cout << cnt << " occurrences" << endl;
  for(int i = 0; i < (int)freq.size(); i++)
    cout << freq[i] << endl;
  return 0;
}
