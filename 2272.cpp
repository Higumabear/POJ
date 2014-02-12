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
const int INF = 10000000;

int mato(double a){
  if(a <= 3.0) return 100;
  if(a <= 6.0) return 80;
  if(a <= 9.0) return 60;
  if(a <= 12.0) return 40;
  if(a <= 15.0) return 20;

  return 0;
}

int main(){
  double a[12];
  while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] 
	>> a[6] >> a[7] >> a[8] >> a[9] >> a[10] >> a[11]){
    if(a[0] == -100) break;
    int N = 0, M = 0;
    for(int i = 0; i < 6; i += 2){
      N += mato(hypot(a[i], a[i + 1]));
    }

    for(int i = 6; i < 12; i += 2){
      M += mato(hypot(a[i], a[i + 1]));
    }

    cout << "SCORE: " << N << " to " << M << ", ";
    if(N == M)
      cout << "TIE." << endl;
    else if(N > M)
      cout << "PLAYER 1 WINS." << endl;
    else      
      cout << "PLAYER 2 WINS." << endl;
  }
  return 0;
}