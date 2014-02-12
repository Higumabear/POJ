#include <iostream>

using namespace std;

int main(){
  int a;
  cin >> a;
  for(int i = 0; i < a; i++){
    int d[4];
    for(int j = 0; j < 4; j++) cin >> d[j];
    if(d[3] - d[2] == d[2] - d[1] && d[2] - d[1] == d[1] - d[0])
      cout << d[0] << " " << d[1] << " "
	   << d[2] << " " << d[3] << " "
	   << 2 * d[3] - d[2] << endl;
    else if(d[1] % d[0] == 0
	    && d[2] % d[1] == 0
	    && d[3] % d[2] == 0
	    && d[3] / d[2] == d[2] / d[1]
	    && d[2] / d[1] == d[1] / d[0])
      cout << d[0] << " " << d[1] << " "
	   << d[2] << " " << d[3] << " "
	   << d[3] * d[3] / d[2] << endl; 

  }
}