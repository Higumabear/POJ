#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

int lastnotzero(int n){
  while(n % 10 == 0){
    n /= 10;
  }
  return n % 100000;
}

int main(int argc, char **argv){
  int n;
  while(cin >> n){
    int s = 1;
    if(n == 0) cout << 1 << endl;
    else{
      for(int i = 1; i <= n; i++){
	s *= i;
	s = lastnotzero(s);
      }
    }
    cout << setw(5) << n << " -> " << s % 10 << endl;
  }
  return 0;
}