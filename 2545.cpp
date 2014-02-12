#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

set<ll> ham;

ll a, b, c, d;

int main(){
  cin >> a >> b >> c >> d;
  ll a1[100], a2[100], a3[100];
  a1[0] = 1, a2[0] = 1, a3[0] = 1;
  for(int i = 0; i < 80; i++){
    a1[i + 1] = a1[i] * a;
    a2[i + 1] = a2[i] * b;
    a3[i + 1] = a3[i] * c;
  }

  for(int i = 0; i <= 80; i++){
    for(int j = 0; j <= 80; j++){
      for(int k = 0; k <= 80; k++){
	if(i * log(a) + j * log(b) + k * log(c) 
	   < 18 * log(10)){
	  ham.insert(a1[i] * a2[j] * a3[k]);
	}
      }
    }
  }
  
  int k = 0;
  for(set<ll>::iterator it = ham.begin(); 
      it != ham.end(); it++, k++){
    if(k == d){
      cout << *it << endl;
      break;
    }
  }
  return 0;
}