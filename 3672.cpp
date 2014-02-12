#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv){
  int M, T, U, F, D;
  cin >> M >> T >> U >> F >> D;

  int t = 0;
  int i;
  for(i = 0; i < T; i++){
    char c;
    cin >> c;
    switch(c){
    case 'f':
      t += (2 * F);
      break;
    default:
      t += (U + D);
      break;
    }
    if(t > M) break;
  }
  cout << i << endl;
  return 0;
}