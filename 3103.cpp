#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv){
  double x, y, z; int n;
  scanf("%lf %lf %lf %d", &x, &y, &z, &n);
  for(int i = 0; i < n; i++)
    printf("0 0 %.9f %.9f %.9f %.9f\n",
	   i * z / n, x, y, (i + 1) * z / n);
  return 0;
}