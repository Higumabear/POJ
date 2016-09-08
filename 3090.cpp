// Time-stamp: <Sat May 21 03:20:02 東京 (標準時) 2016>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int d[1001];

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a % b);
}
int main(int argc, char **argv){
  fill(d, d + 1001, 0);
  for(int y = 1; y <= 1000; y++)
    for(int x = 1; x < y; x++)
      if(gcd(y, x) == 1) d[y]++;

  int N; cin >> N;
  for(int i = 0; i < N; i++){
    int a; cin >> a;

    int cnt = 0;
    for(int j = 1; j <= a; j++) 
      cnt += d[j];
    cout << i + 1 << " " << a << " " << cnt * 2 + 3 << endl;
  }
  return 0;
}