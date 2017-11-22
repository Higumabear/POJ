// Time-stamp: <Mon Mar 06 21:04:23 東京 (標準時) 2017>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <iostream>


using namespace std;
int d[200];
int main(int argc, char **argv){
  int n;
  while(cin >> n, n){
    vector<int> d(n);
    for(int i = 1; i <= n; i++) d[i - 1] = i;
    
    //int m; cin >> m;
    for(int m = 2; ; m++){
      vector<int> e = d;
      int idx = 0;
      while(e.size() != 1){
	e.erase(e.begin() + idx);
	idx = (idx + m - 1) % e.size();
      }
      //cout << e[0] << endl;
      if(e[0] == 2){
	cout << m << endl;
	break;
      }
    }
  }
  
  return 0;
}
