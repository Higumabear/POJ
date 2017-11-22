#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

const double PI = acos(-1.0);
char s[100];

int main(){
  int x1,x2,x3,y1,y2,y3;
  int a1,a2,a3,b1,b2,b3;
  char tns, tew, ins, iew;

  gets(s);
  gets(s);
  gets(s);
  scanf("%d^%d'%d\" %cL\n", &x1, &x2, &x3, &tns);
  scanf("and %d^%d'%d\" %cL.\n", &y1, &y2, &y3, &tew);
  gets(s);
  scanf("%d^%d'%d\" %cL\n", &a1, &a2, &a3, &ins);
  scanf("and %d^%d'%d\" %cL.\n", &b1, &b2, &b3, &iew);
  gets(s);

  double ph1 = x1 + 1.0 * x2 / 60 + 1.0 * x3 / 3600;
  double th1 = y1 + 1.0 * y2 / 60 + 1.0 * y3 / 3600;
  if(tns == 'S') ph1 *= -1;
  if(tew == 'E') th1 *= -1;

  double ph2 = a1 + 1.0 * a2 / 60 + 1.0 * a3 / 3600;
  double th2 = b1 + 1.0 * b2 / 60 + 1.0 * b3 / 3600;
  if(ins == 'S') ph2 *= -1;
  if(iew == 'E') th2 *= -1;


  ph1 = ph1 * PI / 180;
  ph2 = ph2 * PI / 180;
  th1 = th1 * PI / 180;
  th2 = th2 * PI / 180;

  //double r = 6875.0 / 2.0;
  double X1 = cos(th1) * cos(ph1);
  double Y1 = sin(th1) * cos(ph1);
  double Z1 = sin(ph1);
  double X2 = cos(th2) * cos(ph2);
  double Y2 = sin(th2) * cos(ph2);
  double Z2 = sin(ph2);

  double D = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2) + pow(Z1 - Z2, 2));
  //dump(D);
  double t = asin(D / 2) * 2;
  int d = (int)(t * 6875 * 50 + 0.5);
  //D = r * acos((2.0 * pow(r, 2) - pow(D, 2)) / (2.0 * pow(r, 2)));
  //dump(D);
  // cout << sqrt(pow(X1/r, 2) + pow(Y1/r, 2) + pow(Z1/r, 2)) << endl;
  // cout << sqrt(pow(X1, 2) + pow(Y1, 2) + pow(Z1, 2)) << endl;
  // cout << sqrt(x2*x2+Y2*Y2+Z2*Z2) << endl;
  printf("The distance to the iceberg: %.2f miles.\n", d / 100.0);
  if(d < 10000)
    puts("DANGER!");
  return 0;
}
