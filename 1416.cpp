// Time-stamp: <Sun Jan 29 15:57:48 東京 (標準時) 2017>
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

int limit, a;
vector<string> ans;
map<int, int> dup;

void check(vector<string> &s){
  int v = 0;
  for(int i = 0; i < s.size(); i++)
    v += atoi(s[i].c_str());
  if(v <= limit && a <= v){
    a = v;
    ans = s;
    dup[a]++;
  }
  return;
}

void rec(string s, vector<string> d){
  if(s.empty()){
    check(d);
    return;
  }
  for(int i = 1; i <= s.size(); i++){
    string t = s.substr(0, i);
    vector<string> tmp = d;
    tmp.push_back(t);

    string rem = s.substr(i);
    rec(rem, tmp);
  }
  return;
}
int main(int argc, char **argv){
  int n;
  string s;
  while(cin >> n >> s){
    if(n == 0 && s == "0") break;
    a = 0;
    limit = n;
    ans.clear();
    dup.clear();
    rec(s, vector<string>());
    
    if(ans.size() == 0) cout << "error" << endl;
    else if(dup[a] > 1) cout << "rejected" << endl;
    else{
      cout << a << " ";
      for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
