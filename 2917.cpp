#include <iostream>
#include <map>

using namespace std;

map<int, int> pf(int n){
  map<int, int> ret;
  for(int i = 2; i * i <= n; i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n]++;
  return ret;
}

int main(){
  int T, idx = 0;
  cin >> T;
  while(T--){
    int n; cin >> n;
    map<int, int> p = pf(n);

    int ans = 1;
    map<int, int>::iterator it = p.begin();
    for(; it != p.end(); it++)
      ans *= (2 * it->second + 1);
    cout << "Scenario #" << ++idx << ":" << endl;
    cout << (ans + 1) / 2 << endl << endl;;
  }
}
