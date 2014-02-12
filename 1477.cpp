#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int main(){
  int n, index = 1;
  int brick[100];
  while(cin >> n, n != 0){
    int average = 0;
    for(int i = 0; i < n; i++){
      cin >> brick[i];
      average += brick[i];
    }
    average /= n;
    int ret = 0;
    for(int i = 0; i < n; i++)
      ret += abs(average - brick[i]);
    cout << "Set #" << index++ << endl
	 << "The minimum number of moves is " 
	 << ret / 2 << "." << endl << endl;
  }
  return 0;
}