// Time-stamp: <Sat Nov 12 21:26:32 東京 (標準時) 2016>
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

void change(string s){
  string t = s;
  reverse(ALL(t));
  if(t.find("re") == 0 && s != "after"){
    cout << "one who " << s.substr(0, s.length() - 2) << "s ";
  }
  else if(t.find("gni") == 0){
    cout << "to actively " << s.substr(0, s.length() - 3) << " ";
  }
  else if(t.find("ezi") == 0){
    cout << "change into " << s.substr(0, s.length() - 3) << " ";
  }
  else if(t.find("s") == 0){
    cout << "multiple instances of " << s.substr(0, s.length() - 1) << " ";
  }
  else if(t.find("noit") == 0){
    cout << "the process of " << s.substr(0, s.length() - 4) << "ing ";
  }
  else cout << s << " ";
}

int main(int argc, char **argv){
  int N;
  cin >> N;
  while(N--){
    string s;
    cin >> s;
    
    vector<string> r;
    if(s.find("anti") == 0) s = "against " + s.substr(4);
    if(s.find("post") == 0) s = "after " + s.substr(4);
    if(s.find("pre") == 0) s = "before " + s.substr(3);
    if(s.find("re") == 0) s = s.substr(2) + " again";
    if(s.find("un") == 0) s = "not " + s.substr(2);

    //cout << s << endl;
    stringstream ss(s);
    while(ss >> s) change(s);
    cout << endl;
  }
  return 0;
}
