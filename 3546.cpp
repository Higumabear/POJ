// Time-stamp: <Sun Feb 12 01:29:27 東京 (標準時) 2017>
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

char f[11][11];

int check(int K){
  int cnt = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j + K <= 10; j++){
      bool g = true;
      for(int k = 0; k < K; k++)
	g &= (f[i][j + k] == '1');
      if(g){
	for(int k = 0; k < K; k++)
	  f[i][j + k] = '.';
	cnt++;
      }
    }
  }
  for(int j = 0; j < 10; j++){
    for(int i = 0; i + K <= 10; i++){
      bool g = true;
      for(int k = 0; k < K; k++)
	g &= (f[i + k][j] == '1');
      if(g){
	for(int k = 0; k < K; k++)
	  f[i + k][j] = '.';
	cnt++;
      }
    }
  }  
  return cnt;
}

int main(int argc, char **argv){
  for(int i = 0; i < 10; i++) gets(f[i]);
  for(int i = 0; i < 10; i++){
    if(f[0][i] == '1' || f[9][i] == '1' ||
       f[i][0] == '1' || f[i][9] == '1'){
      cout << "incorrect" << endl;
      return 0;
    }
  }
  for(int i = 1; i < 9; i++){
    for(int j = 1; j < 9; j++){
      if(f[i][j] == '1' && 
	 (f[i + 1][j - 1] == '1' || f[i + 1][j + 1] == '1')){
	cout << "incorrect" << endl;
	return 0;
      }
    }
  }
  if(check(5) > 0){
    cout << "incorrect" << endl;
  }else{
    int n4 = check(4);
    int n3 = check(3);
    int n2 = check(2);
    int n1 = check(1);
    if(n4 == 1 && n3 == 2 && n2 == 3 && n1 == 4){
      cout << "correct" << endl;
    }else{
      cout << "incorrect" << endl;
    }
  }
  return 0;
}
