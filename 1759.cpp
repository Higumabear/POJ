#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;
const int INF = (1 << 31) - 1;


int main(int argc, char **argv){
  int N;
  double A;
  scanf("%d %lf", &N, &A);

  double ans = 1e100;
  double ub = 1e50, lb = 0.0;
  for(int i = 0; i < 1000; i++){
    double mid = (ub + lb) * 0.5;

    bool flag = true;
    double pp = A, p = mid;
    for(int j = 2; j < N; j++){
      double cur = 2.0 * p + 2.0 - pp;
      pp = p, p = cur;
      if(cur < 0) flag = false;
    }

    if(!flag) lb = mid;
    else{
      ub = mid;
      ans = min(ans, p);
    }
  }
  printf("%.2f\n", ans);
  return 0;
}
