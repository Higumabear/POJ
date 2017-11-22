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

bool isnumber(string s){
  bool ok = (s[0] == '-' || ('0' <= s[0] && s[0] <= '9'));
  for(int i = 1; i < s.size(); i++)
    if(!('0' <= s[i] && s[i] <= '9')) ok = false;
  return ok;
}

int s2i(string s){
  stringstream ss(s);
  int x;
  ss >> x;
  return x;
}

string toupper(string s){
  for(int i = 0; i < s.size(); i++){
    if('a' <= s[i] && s[i] <= 'z')
      s[i] = s[i] - 'a' + 'A';
  }
  return s;
}

struct strings{
  string s, upper;
  bool operator<(const strings &r)const{
    return upper < r.upper;
  }
};

int main(){
  string s;
  while(1){
    getline(cin, s);
    if(s == ".") break;

    for(int i = 0; i < s.size(); i++)
      if(s[i] == ',' || s[i] == '.') s[i] = ' ';

    vector<bool> flag;
    vector<int> num;
    vector<strings> str;
    stringstream ss(s);
    while(ss >> s){
      if(isnumber(s)){
	num.push_back(s2i(s));
	flag.push_back(true);
      }else{
	strings tmp;
	tmp.s = s;
	tmp.upper = toupper(s);
	
	str.push_back(tmp);
	flag.push_back(false);
      }
    }
    sort(ALL(num));
    sort(ALL(str));

    int i = 0, j = 0;
    for(int k = 0; k < flag.size(); k++){
      if(flag[k]){
	cout << num[i++];
      }else{
	cout << str[j++].s;
      }
      if(k != flag.size() - 1) cout << ", ";
    }
    cout << "." << endl;
  }
  return 0;
}
