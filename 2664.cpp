#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
  ios::sync_with_stdio(false);
  int k, m;
  while(cin >> k, k != 0){
    cin >> m;
    vector<string> cource(k);
    for(int i = 0; i < k; i++) cin >> cource[i];

    bool isOK = true;
    for(int p = 0; p < m; p++){
      int c, r; cin >> c >> r;
      int cnt = 0;
      
      for(int i = 0; i < c; i++){
	string nowc; cin >> nowc;
	if(find(cource.begin(), cource.end(), nowc) != cource.end())
	  cnt++;
      }
      
      if(cnt < r) isOK &= false;
    }
    if(isOK) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  
  return 0;
}