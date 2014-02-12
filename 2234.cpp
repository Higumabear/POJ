#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv){
  int M;
  while(cin >> M){
    int a;
    int ret = 0;
    for(int i = 0; i < M; i++){
      cin >> a;
      ret ^= a;
    }
    if(ret != 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}