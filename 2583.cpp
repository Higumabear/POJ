#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int poly(int a, int b, int c, int x){
  return a * x * x + b * x + c;
}

int main(int argc, char **argv){
  int f0, f1, f2;
  while(cin >> f0 >> f1 >> f2){
    int A = (f2 - 2 * f1 + f0) / 2;
    int C = f0;
    int B = f1 - f0 - A;
    cout << poly(A, B, C, 3) << " "
	 << poly(A, B, C, 4) << " "
	 << poly(A, B, C, 5) << endl;
  }
  return 0;
}