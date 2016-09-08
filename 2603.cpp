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

using namespace std;

map<int, int> prime_factor(int n){
  map<int, int> ret;
  for(int i = 2; i * i <= n; i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(){
  map<int, int> q;
  for(int i = 0; i < 10; i++){
    int a; cin >> a;
    if(a == 1)  continue;
    map<int, int> p = prime_factor(a);
    for(map<int, int>::iterator it = p.begin(); 
	it != p.end(); it++) q[it->first] += it->second;
  }
  long long ans = 1;
  for(map<int, int>::iterator it = q.begin(); it != q.end(); it++)
    ans *= (it->second + 1);
  cout << ans % 10 << endl;
  return 0;
}