#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[1000010];

vector<int> divisor(int n){
  vector<int>ret;
  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      ret.push_back(i);
      if(i != n / i) ret.push_back(n / i);
    }
  }
  return ret;
}

int main(){
  while(~scanf("%s", s)){
    if(s[0] == '.') break;
    int L = strlen(s) / sizeof(char);
    
    vector<int> d = divisor(L);
    sort(d.begin(), d.end());
    for(int i = 0; i < (int)d.size(); i++){
      bool isok = true;
      for(int j = 1; j < L / d[i]; j++){
	for(int k = 0; k < d[i]; k++){
	  if(s[k] != s[k + d[i] * j]){
	    isok = false;
	    goto L1;
	  }
	}
      }
    L1:;
      if(isok){
	printf("%d\n", L / d[i]);
	break;
      }
    }
  }
}