// Time-stamp: <Fri Apr 14 21:50:09 東京 (標準時) 2017>
#include <cstdio>

using namespace std;

int x[10] = {
  6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179
};
int y[10] = {
  8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161
};

int main(int argc, char **argv){
  for(int i = 0; i < 10; i++)
    printf("%10d%10d\n", x[i], y[i]);
  return 0;
}
