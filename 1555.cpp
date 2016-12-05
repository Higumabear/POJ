// Time-stamp: <Sat Oct 08 00:17:08 東京 (標準時) 2016>
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

string func1(int a){
  if(a == 1){
    return "";
  }else if(a == -1){   
    return "-";
  }else{
    stringstream ss;
    ss << a;
    string ret; ss >> ret;
    return ret;
  }
}

string func2(int a){
  if(a == 1){
    return "x";
  }else{
    stringstream ss;
    ss << a;
    string ret; ss >> ret;
    return "x^" + ret;
  }
}

int main(int argc, char **argv){
  vector<int> a(9);
  while(cin >> a[0] >> a[1] >> a[2] 
	>> a[3] >> a[4] >> a[5] 
	>> a[6] >> a[7] >> a[8]){
    vector<pair<int, int> > c;
    for(int i = 0; i < 9; i++)
      if(a[i] != 0)
	c.push_back(make_pair(a[i], 8 - i));
    
    for(int i = 0; i < c.size(); i++){

      //最初の桁
      if(i == 0){
	if(c[i].second == 0) cout << c[i].first;
	else cout << func1(c[i].first) << func2(c[i].second) << " ";
      //最初以外の桁
      }else{
	if(c[i].second == 0){
	  if(c[i].first < 0) cout << "- " << -c[i].first;
	  else cout << "+ " << c[i].first;
	}
	else{
	  if(c[i].first < 0)
	    cout << "- " << func1(-c[i].first) << func2(c[i].second) << " ";	
	  else
	    cout << "+ " << func1(c[i].first) << func2(c[i].second) << " ";	
	}
      }
    }
    if(c.size() == 0) cout << 0 << endl;
    cout << endl;
  }
  return 0;
}
