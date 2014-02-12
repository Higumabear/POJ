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

int main(){
  int w[3];
  scanf("%d %d %d", &w[0], &w[1], &w[2]);
  for(int i = 0; i < 3; i++){
    if(w[i] < 168){
      printf("CRASH %d\n", w[i]);
      break;
    }
    if(i == 2) printf("NO CRASH\n");
  }
  return 0;
}