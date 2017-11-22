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
  int T, N;
  char c;

  cin >> T;
  while(T--){
    vector<char> name;
    cin >> N;
    for(int i = 0; i < 2 * N; i++){
      cin >> c;
      if(i < N) name.push_back(c);
    }
    
    vector<char> match[0xff];
    for(int i = 0; i < 2 * N; i++){
      string s; cin >> s;
      for(int j = 2; j < s.size(); j++)
	match[s[0]].push_back(s[j]);
    }

    // for(int i = 0; i < match[0].size(); i++)
    //   cout << 0 << " " << match[0][i] << endl;

    sort(ALL(name));
    
    queue<char> Q;
    for(int i = 0; i < N; i++) Q.push(name[i]);

    vector<char> keep(0xff, '-');
    while(!Q.empty()){
      char m = Q.front(); Q.pop();
      char f = match[m].front();
      match[m].erase(match[m].begin());
      if(keep[f] == '-'){ //accept
	keep[f] = m;
	keep[m] = f;
      }else{
	if(find(ALL(match[f]), keep[f]) >
	   find(ALL(match[f]), m)){  //acecpt
	  Q.push(keep[f]);
	  keep[f] = m;
	  keep[m] = f;
	}else{ //reject
	  Q.push(m);
	}
      }
    }
    for(int i = 0; i < N; i++)
      cout << name[i] << " " << keep[name[i]] << endl;
    cout << endl;
  }
  return 0;
}
