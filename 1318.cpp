// Time-stamp: <Thu Dec 08 21:45:35 東京 (標準時) 2016>
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
  string s;
  map<string, vector<string> > p; 
  while(cin >> s){
    if(s == "XXXXXX") break;
    string t(s);
    sort(ALL(t));
    p[t].push_back(s);
  }
  map<string, vector<string> >::iterator it = p.begin();
  for(; it != p.end(); it++) sort(ALL(it->second));
  while(cin >> s){
    if(s == "XXXXXX") break;
    sort(ALL(s));
    if(p.count(s)){
      vector<string> q = p[s];
      for(int i = 0; i < q.size(); i++) cout << q[i] << endl;
      cout << "******" << endl;
    }else cout << "NOT A VALID WORD" << endl << "******" << endl;
  }
  return 0;
}
