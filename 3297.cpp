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
  map<string, vector<string> > assign;
  map<string, int> proj_num;
  map<int, vector<string> > num_proj;
  string proj_name;
  while(1){
    string s;
    getline(cin, s);
    if(s == "0") break;
    if(s == "1"){
      map<string, vector<string> >::iterator it = assign.begin();
      for(; it != assign.end(); it++){
	vector<string> t = it->second;
	sort(ALL(t));
	t.erase(unique(ALL(t)), t.end());
	if(t.size() >= 2 || t.size() == 0) continue;
	proj_num[t[0]]++;
      }
      map<string, int>::iterator itt = proj_num.begin();
      for(; itt != proj_num.end(); itt++)
	num_proj[itt->second].push_back(itt->first);

      map<int, vector<string> >::reverse_iterator ittt = num_proj.rbegin();
      for(; ittt != num_proj.rend(); ittt++){
	vector<string> tmp = ittt->second;
	sort(ALL(tmp));
	for(int i = 0; i < tmp.size(); i++)
	  if(tmp[i] != "")
	    cout << tmp[i] << " " << ittt->first << endl;
      }
      assign.clear();
      proj_num.clear();
      num_proj.clear();
      proj_name = "";
    }

    if(isupper(s[0])){
      proj_name = s;
      proj_num[proj_name] = 0;
    }
    else{
      assign[s].push_back(proj_name);
    }
  }
  return 0;
}