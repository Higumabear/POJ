#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string a, b;
    cin >> a >> b;

    int A = 0, B = 0;
    bool samepos[100];
    fill(samepos, samepos + 100, false);
    for(int j = 0; j < (int)a.length(); j++){
      if(a[j] == b[j]){
	A++;
	samepos[j] = true;
      }
    }

    for(int p = 0; p < (int)a.length(); p++){
      for(int q = 0; q < (int)a.length(); q++){
	if(!samepos[p] && !samepos[q] && p != q && a[p] == b[q]) B++;
      }
    }
    cout << A << "A" << B << "B" << endl;
  }
}