// Time-stamp: <Thu Oct 27 23:18:15 東京 (標準時) 2016>
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
  map<char, vector<string> > b, w;
  vector<string> s(17);
  for(int i = 0; i < 17; i++) cin >> s[i];
    
  for(int i = 15; i >= 1; i -= 2){
    for(int j = 2; j < 33; j += 4){
      stringstream ss;
      string t;
      if(!isalpha(s[i][j])) continue;
      ss << (char)(j / 4 + 'a');
      ss << (char)(7 - i / 2 + '1');
      ss >> t;
      if(s[i][j] <= 'Z') w[s[i][j]].push_back(t);
    }
  }
  for(int i = 1; i <= 15; i += 2){
    for(int j = 2; j < 33; j += 4){
      stringstream ss;
      string t;
      if(!isalpha(s[i][j])) continue;
      ss << (char)(j / 4 + 'a');
      ss << (char)(7 - i / 2 + '1');
      ss >> t;
      if('a' <= s[i][j] && s[i][j] <= 'z') b[s[i][j]].push_back(t);
    }
  }

  string al("KQRBNP");
  map<char, vector<string> >::iterator it = w.begin();
  stringstream ss;
  ss << "White: ";
  for(int i = 0; i < al.size(); i++){
    vector<string> u = w[al[i]];
    for(int v = 0; v < u.size(); v++){
      if(al[i] != 'P') ss << al[i];
      ss << u[v] << ",";
    }
  }
  string str = ss.str();
  cout << str.substr(0, str.size() - 1) << endl;
  
  al = "kqrbnp";
  ss.str("");
  ss << "Black: ";
  for(int i = 0; i < al.size(); i++){
    vector<string> u = b[al[i]];
    for(int v = 0; v < u.size(); v++){
      if(al[i] != 'p') ss << (char)toupper(al[i]);
      ss << u[v] << ",";
    }
  }
  str = ss.str();
  cout << str.substr(0, str.size() - 1) << endl;
  return 0;
}
