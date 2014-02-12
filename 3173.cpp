#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int table[21][21];

int main(){
  int N, S;
  cin >> N >> S;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(j <= i){
	table[i][j] = S;
	if(S % 10 == 9) S = 1;
	else S++;
      }
      else table[i][j] = 0;
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i <= j){
	if(j < N - 1)
	  cout << table[j][i] << " ";
	else 
	  cout << table[j][i];
      }else{
	cout << "  ";
      }
    }
    cout << endl;
  }
  return 0;
}