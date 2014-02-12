#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

ll comb(ll n, ll r){
  r = min(r, n - r);
  ll ret = 1;
  for(ll i = 0; i < r; i++) ret = (ret * (n - i) / (i + 1));
  return ret;
}

int main(){
  ll w, h;
  while(cin >> w >> h){
    if(w == 0 && h == 0) break;
    cout << comb(w + h, h) << endl;
  }
  return 0;
}