#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int mabs(int a){return (a > 0) ? a : -a;}

int main(int argc, char **argv){
  string ret;
  int x;
  cin >> x;
  if(x == 0){
    cout << "0" << endl;
    return 0;
  }
  while(x != 1){
    if(mabs(x) % 2 == 1){
      ret += '1';
      x = (x - 1) / -2;
    }else{
      ret += '0';
      x /= -2;
    }
  }
  cout << "1";
  for(int i = (int)ret.length() - 1; i >= 0; i--){
    cout << ret[i];
  }
  cout << endl;
  return 0;
}