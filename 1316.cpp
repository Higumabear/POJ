#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool selfish[10000];

int gene(int a){
  int di = 0;
  int b = a;
  while(a > 0){
    di += a % 10;
    a /= 10;
  }
  return di + b;
}

int main(int argc, char **argv){
  fill(selfish, selfish + 10000, true);
  for(int i = 1; i < 10000; i++){
    int p = gene(i);
    if(p < 10000) selfish[p] = false;
  }
  for(int i = 1; i < 10000; i++) if(selfish[i]) cout << i << endl;
  return 0;
}