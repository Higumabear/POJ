#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int y[110000], x[110000];

int main(){
  int r = 1;
  //int next = r * 6;
  y[0] = x[0] = 0;
  int prevx = 1, prevy = 0;
  int i = 1;
  while(i < 100010){
    for(int side = 0; side < 6; side++){
      for(int cell = 0; cell < r; cell++){
	//if(side + cell == 0) continue;
	if(side == 0){
	  x[i] = prevx - 1, y[i] = prevy + 1;
	}else if(side == 1){
	  x[i] = prevx - 1, y[i] = prevy;
	}else if(side == 2){
	  x[i] = prevx, y[i] = prevy - 1;
	}else if(side == 3){
	  x[i] = prevx + 1, y[i] = prevy - 1;
	}else if(side == 4){
	  x[i] = prevx + 1, y[i] = prevy;
	}else{
	  x[i] = prevx, y[i] = prevy + 1;
	}
	//cout << i + 1 << " -> " << x[i] << " " << y[i] << endl;

	prevx = x[i], prevy = y[i];
	i++;
      }
      //}
    }
    r++;
    prevx++;
  }

  int idx;
  while(cin >> idx) 
    cout << x[idx - 1] << " " << y[idx - 1] << endl;
  return 0;
}
