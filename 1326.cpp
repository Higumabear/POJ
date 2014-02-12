#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv){
  string a, b;
  int mile; char type;
  int sum = 0;
 L1:
  while(cin >> a, a != "#"){
    if(a == "0"){
      cout << sum << endl;
      sum = 0;
      goto L1;
    }
    cin >> b >> mile >> type;
    switch(type){
    case 'F':
      sum += 2 * mile;
      break;
    case 'B':
      sum += (mile + (int)(0.5 * mile + 0.5));
      break;
    default :
      if(mile < 500) sum += 500;
      else sum += mile;
      break;
    }
  }
  return 0;
}