// Time-stamp: <Thu Dec 15 22:51:59 東京 (標準時) 2016>
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

int main(int argc, char **argv){
  int K, E, idx = 0;
  while(cin >> K >> E){
    set<string> keyword;
    map<string, string> chg;
    for(int i = 0; i < K; i++){
      string s; cin >> s;
      keyword.insert(s);
    }
    cin.ignore();
    vector<string> ans;
    int m = 0;
    for(int i = 0; i < E; i++){
      string str, lower;
      getline(cin, str);
      lower = str;
      for(int i = 0; i < lower.size(); i++)
	if(isalpha(lower[i])) lower[i] = tolower(lower[i]);
	else lower[i] = ' ';
      chg[lower] = str;
      int c = 0;
      stringstream ss(lower);
      for(string s; ss >> s;) if(keyword.count(s)) c++;

      if(c > m){
	m = c;
	ans.clear();
	ans.push_back(chg[lower]);
      }else if(c == m) 
	ans.push_back(chg[lower]);
    }    
    cout << "Excuse Set #" << ++idx << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    cout << endl;
  }
  return 0;
}
