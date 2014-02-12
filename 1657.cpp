#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int main(){
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    char x1c, x2c;
    int x1, x2;
    int y1, y2;
    cin >> x1c >> y1 >> x2c >> y2;
    x1 = x1c - 'a';
    x2 = x2c - 'a';

    int diffx = abs(x1 - x2);
    int diffy = abs(y1 - y2);

    if(diffx == 0 && diffy == 0) cout << "0 0 0 0" << endl;
    else{
      //1
      cout << max(diffx, diffy) << " ";
      
      //2
      if(diffx == diffy || diffx * diffy == 0)
	cout << 1 << " ";
      else cout << 2 << " ";
      
      
      //3
      if(diffx * diffy == 0) cout << 1 << " ";
      else cout << 2 << " ";
      
      
      //4
      if((diffx + diffy) % 2 == 0){
	if(diffx == diffy) cout << 1 << endl;
	else cout << 2 << endl;
      }else cout << "Inf" << endl;
    }
  }
  return 0;
}
