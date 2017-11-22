#include <iostream>
#include <vector>
#include <map>
#include <sstream>

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
  string s;
  while(1){
    getline(cin, s);
    if(s == "0") break;
    stringstream ss(s);

    int d = 1;
    int a, x;
    while(ss >> a >> x)
      for(int i = 0; i < x; i++) d *= a;
    
    d--;
    map<int, int> ans = pf(d);
    map<int, int>::reverse_iterator it = ans.rbegin();
    for(; it != ans.rend(); it++)
      cout << it->first << " " << it->second << " ";
    cout << endl;
  }
}
