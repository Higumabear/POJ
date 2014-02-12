#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int main(int argc, char **argv){
  //vector<int> f(22);
  int f = 0;
  for(int i = 0; i < 20; i++){
    int a;
    cin >> a;
    f |= a << i;
  }
  f <<= 1;


  int ret = 1000000;
  for(int S = 0; S < 1 << 20; S++){
    int m;
    m = f;
    int flip = __builtin_popcount(S);
    if(ret > flip){
      for(int i = 0; i < 20; i++){
	if(S & 1 << i){
	  m ^= 7 << i;
	}
      }
      m &= ~1;
      m &= ~(1 << 21);
      if(m == 0){
	ret = flip;
      }
    }
  }
  cout << ret << endl;
  return 0;
}
