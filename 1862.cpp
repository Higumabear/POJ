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

double a[100];

int main(){
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> a[i];

  sort(a, a + N, greater<double>());
  for(int i = 1; i < N; i++){
    a[i] = 2 * sqrt(a[i] * a[i - 1]);
  }
  printf("%.3f\n", a[N - 1]);
  return 0;
}