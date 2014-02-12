#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <cmath>

const double eps = 1e-9;
using namespace std;

int main(int argc, char **argv){
  int n; scanf("%d", &n);
  for(int d = 2; d <= n; d++){
    for(int a = 2; a < n; a++){
      if(a > d) continue;
      for(int b = a; b < n; b++){
	for(int c = b; c < n; c++){
	  int tmp = a * a * a + b * b * b + c * c * c;
	  if(d*d*d == tmp){
	    printf("Cube = %d, Triple = (%d,%d,%d)\n",
		   d, a, b, c);
	  }
	}
      }
    }
  }
  return 0;
}