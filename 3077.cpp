#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;

    if(a > 10){
      int keta = -1;
      int b = a;
      while(b){
	b /= 10;
	keta++;
      }
      double tmp = a;
      int dec = 10;
      for(int j = 1; j <= keta; j++){
	tmp /= dec;
	tmp += 0.5;
	int t = tmp;
	tmp = t;
	tmp *= dec;
	dec *= 10;
      }
      cout << (int)tmp << endl;
    }else{
      cout << a << endl;
    }
  }
  return 0;
}