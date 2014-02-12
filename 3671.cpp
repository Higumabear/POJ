#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int cow[30000];

int main(){
  int N;
  int allsum = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> cow[i];
    cow[i]--;
    allsum += cow[i];
  }


  int cnt = 1000000000;
  int leftsum = 0;
  int rightsum = allsum;
  for(int i = 0; i <= N; i++){
    cnt = min(cnt, leftsum + abs(rightsum - (N - i)));
    if(cow[i] == 1){
      leftsum++;
      rightsum--;
    }
  }
  cout << cnt << endl;
  return 0;
}
