#include <cstdio>
using namespace std;
int main(){
  double cur = 0.0, prev = 0.0;
  scanf("%lf", &prev);
  while(scanf("%lf", &cur), cur < 300){
    printf("%.2lf\n", cur - prev);
    prev = cur;
  }
  printf("End of Output\n");
}