#include <iostream>
using namespace std;

int main(){
  int bi[31];
  for(int i = 0; i <= 30; i++){
    bi[i] = 1 << i;
  }

  int N; cin >> N; 
  while(N--){
    int X;
    cin >> X;
    int XX = X;
    while(X & (X - 1)){
      for(int i = 30; i >= 0; i--){
	if(bi[i] < X){
	  X -= bi[i];
	  break;
	}
      }
    }
    cout << 1 + XX - X << " " << (XX - X) + X * 2 - 1 << endl;
  }
}
