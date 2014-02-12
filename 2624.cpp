#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <complex>
using namespace std;
typedef long long ll;
const int INF = 10000000;
const double eps = 1e-6;

int main(){
  complex<double> a, b, c, d, x;
  while(cin >> a.real() >> a.imag() >> b.real() >> b.imag()
	>> c.real() >> c.imag() >> d.real() >> d.imag()){
    if(abs(a - b) < eps){
      b = c;
      c = a;
      b = d;
      a = b;
    }else if(abs(b - c) < eps){
      b = d;
    }else if(abs(c - d) < eps){

    }else if(abs(a - c) < eps){
      a = d;
    }else if(abs(b - d) < eps){
      b = c;
      c = d;
    }else{
      a = c;
      c = d;
    }
    x = a + b - c;
    printf("%.3f %.3f\n", x.real(), x.imag());
  }
  return 0;
}