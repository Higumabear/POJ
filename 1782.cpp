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

int main(){
  string s;
  while(getline(cin, s)){
    vector<bool> co(s.size(), false);
    for(int i = 1; i < s.size(); i++)
      co[i] = s[i - 1] == s[i];

    vector<string> ss;
    string tmp;
    for(int i = s.size() - 1; i >= 0; i--){
      tmp.push_back(s[i]);
      if(!co[i]){
	reverse(ALL(tmp));

	int R = tmp.size();
	char c = tmp[0];
	if(R % 9) ss.push_back(string(R % 9, c));
	R -= (R % 9);
	while(R){
	  int v = min(R, 9);
	  ss.push_back(string(v, c));
	  R -= v;
	}
	
	//ss.push_back(tmp);
	tmp = "";
      }
    }

    bool un = false;
    reverse(ALL(ss));
    for(int i = 0; i < ss.size(); i++){
      if(ss[i].size() == 1){
	if(!un){
	  un = true;
	  cout << 1;
	}
	if(ss[i][0] == '1') cout << ss[i][0];
	cout << ss[i][0];
      }else{
	if(un){
	  un = false;
	  cout << 1;
	}
	int R = ss[i].size();
	char c = ss[i][0];
	// while(R){
	//   int v = min(9, R);
	//   cout << v;
	//   if(c == '1') cout << 1;
	//   cout << c;
	//   R -= v;
	// }
	cout << R;
	//if(c == '1') cout << 1;
	cout << c;
      }
    }
    if(un) cout << 1;
    cout << endl;
  }
  return 0;
}
