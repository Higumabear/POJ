#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;



int main(){
  int N;
  while(cin >> N){
    if(N >= 199){
      cout << 0 << endl;
    }else{
      cout << 2*(99 - N / 2) + (N % 2 == 0) << endl;
    }
  }
  return 0;
}
