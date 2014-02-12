#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <cmath>

typedef long long ll;
using namespace std;

int lo[10000];

ll absolute(int a, int b){
  return a > b ? a - b : b - a;
}

int main(int argc, char **argv){
  int n;
  ll sum = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &lo[i]);
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      sum += absolute(lo[i], lo[j]);
    }
  }
  printf("%lld\n", 2 * sum);
  return 0;
}