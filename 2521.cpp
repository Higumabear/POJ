#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int main(){
  int N, M, P, C;
  while(cin >> N >> M >> P >> C){
    if(N == 0 && M == 0 && P == 0 && C == 0) break;
    cout << P - M + N << endl;
  }
  return 0;
}