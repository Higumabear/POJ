#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

int p[101][101];
int r[100], c[100];

bool check(int n){
  for(int i = 0; i < n; i++){
    if(r[i] % 2 == 1 || c[i] % 2 == 1) return false;
  }
  return true;
}
int main(int argc, char **argv){
  int n;
  while(scanf("%d", &n), n){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	scanf("%d", &p[i][j]);

    for(int i = 0; i < n; i++){
      int rsum = 0;
      for(int j = 0; j < n; j++)
	rsum += p[i][j];
      r[i] = rsum;
    }
    for(int j = 0; j < n; j++){
      int csum = 0;
      for(int i = 0; i < n; i++)
	csum += p[i][j];
      c[j] = csum;
    }
    
    if(check(n)){
      printf("OK\n");
      goto L1;
    }
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	r[i] = r[i] + ((p[i][j] == 0) ? 1 : -1);
	c[j] = c[j] + ((p[i][j] == 0) ? 1 : -1);

	// cout << "--------------------" << endl;
	// for(int k = 0; k < n; k++){
	//   cout << r[k] << " ";
	// }
	// cout << endl;
	// for(int l = 0; l < n; l++){
	//   cout << c[l] << " ";
	// }
	// cout << endl;
	// cout << "--------------------" << endl;

	if(check(n)){
	  printf("Change bit (%d,%d)\n", i + 1, j + 1);
	  goto L1;
	}
	r[i] = r[i] + ((p[i][j] == 0) ? -1 : 1);
	c[j] = c[j] + ((p[i][j] == 0) ? -1 : 1);
      }
    }
    printf("Corrupt\n");
  L1:;
  }
}
