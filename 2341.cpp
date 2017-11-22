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
  char c;
  bool s_start = true, w_start = true;
  int cnt = 0;

  string str;
  while((c = getchar()) != -1){
    str += c;
    if(c == '\n'){
      w_start = true;
    }
    else if(c == '.' || c == '?' || c == '!'){
      s_start = w_start = true;
    }
    else if(c == ' ' || c == ':' || c == ',' || c == '-'){
      w_start = true;
    }
    else{
      if(s_start && w_start){

	if(!isalpha(c)) continue;
	if(islower(c)){
	  cnt++;
	  str += '@';
	}
	s_start = w_start = false;
	
      }else if(!s_start && w_start){

	//if(isalpha(c)) continue;
	s_start = w_start = false;
	
      }else if(!s_start && !w_start){

	if(isupper(c)){
	  cnt++;
	  str += '@';
	}
	
      }else{

      }
    }
  }
  cout << cnt << endl;
  //cout << str << endl;
  return 0;
}
