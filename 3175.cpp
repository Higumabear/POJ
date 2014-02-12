#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>

typedef long long ll;
const double eps = 1e-9;

int main(int argc, char **argv){
  double e, bo;
  e = 1.0;
  int l;
  scanf("%d %lf", &l, &bo);
  for(int i = 0; i < l; i++){
    e /= 10;
    bo /= 10;
  }

  for(int i = 0;; i++){
    double l = i + bo;
    double r = (double)(i + bo + e);

    double a = (ll)ceil(l*l);
    double b = (ll)(r * r - eps);
    if(a == b){
      printf("%lld\n", (ll)a);
      break;
    }
  }
  return 0;
}