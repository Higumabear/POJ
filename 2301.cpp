#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv){
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int a, b, s, d;
    cin >> s >> d;
    if((s + d) % 2 != 0 || (s - d) % 2 != 0)cout << "impossible" << endl;
    else{
      a = (s + d) / 2;
      b = (s - d) / 2;
      if(min(a, b) < 0) cout << "impossible" << endl;
      else{
	cout << max(a, b) << " " << min(a, b) << endl;
      }
    }
  }
  return 0;
}