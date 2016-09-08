#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

char output[10000000];
int pos = 0;

void print(int n){
  if(n == 1) output[pos++] = '-';
  else{
    print(n / 3);
    for(int i = 0; i < n / 3; i++) output[pos++] = ' ';
    print(n / 3);
  }
}

int main(){
  int n;
  while(~scanf("%d", &n)){
    int j = 1;
    for(int i = 0; i < n; i++) j *= 3;
    print(j);
    output[pos++]  = '\n';
  }
  printf(output);
  return 0;
}