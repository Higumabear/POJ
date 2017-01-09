// Time-stamp: <Tue Dec 06 21:31:41 東京 (標準時) 2016>
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
  cin >> s;
  
  if(count(ALL(s), '_')){
    bool check = true;
    for(int i = 0; i < s.size(); i++)
      if(isupper(s[i])) check = false;
    if(!check || (s.find("__") != string::npos) || 
       s[0] == '_' || s[s.size() - 1] == '_'){
      cout << "Error!" << endl;
    }else{
      for(int i = 0; i < s.size(); i++) 
	if(s[i] == '_') s[i] = ' ';
      stringstream ss(s);
      string tmp;
      ss >> tmp;
      cout << tmp;
      while(ss >> tmp){
	tmp[0] = toupper(tmp[0]);
	cout << tmp;
      }
      cout << endl;
    }
  }else{

    if(isupper(s[0])) cout << "Error!" << endl;
    else{
      for(int i = 0; i < s.size(); i++){
	if(isupper(s[i])) cout << "_" << (char)tolower(s[i]);
	else cout << s[i];
      }
      cout << endl;
    }
  }
  return 0;
}
