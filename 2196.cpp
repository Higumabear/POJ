#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool e101216(const int n){
  int n10 = n;
  int tmp10 = 0;
  while(n10 > 0){
    tmp10 += (n10 % 10);
    n10 /= 10;
  }

  int n16 = n;
  int tmp16 = 0;
  while(n16 > 0){
    tmp16 += (n16 % 16);
    n16 /= 16;
  }

  int n12 = n;
  int tmp12 = 0;
  while(n12 > 0){
    tmp12 += (n12 % 12);
    n12 /= 12;
  }

  return tmp10 == tmp12 && tmp12 == tmp16;
}

int main(int argc, char **argv){
  for(int i = 2992; i < 10000; i++){
    if(e101216(i)) cout << i << endl;
  }
  return 0;
}