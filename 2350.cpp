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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int main(){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int C;
    scanf("%d", &C);
    vector<int> grade(C);
    for(int j = 0; j < C; j++) scanf("%d", &grade[j]);
    double av = (double)accumulate(grade.begin(), grade.end(), 0) / C;
    int cnt = 0;
    for(int j = 0; j < C; j++) if(av < grade[j]) cnt++;
    printf("%.3f%c\n", (double)100 * cnt / C, '%');
  }
  return 0;
}