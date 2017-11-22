// Time-stamp: <Wed Apr 26 00:48:35 東京 (標準時) 2017>
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

double pi = acos(-1);
double S;


double he(double r){
  return sqrt(S * S - 2 * S * r * r * pi) / (r * pi);
}
double vol(double r){
  //double h = sqrt((S * S - r * r * r * r * pi * pi) / (r * r * pi * pi));
  double h = he(r);
  return pi * r * r * h / 3.0;
}

int main(int argc, char **argv){
  while(cin >> S){
    double lb = EPS, ub = sqrt(S / pi);
    for(int i = 0; i < 1000; i++){
      double v1 = (2 * lb + ub) / 3.0;
      double v2 = (lb + 2 * ub) / 3.0;
      if(vol(v1) > vol(v2)) ub = v2;
      else lb = v1;
    }
    //cout << vol(ub) << endl;
    printf("%.2f\n", vol(ub));
    printf("%.2f\n", he(ub));
    printf("%.2f\n", ub);
  }
  return 0;
}
