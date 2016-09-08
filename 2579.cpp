#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  string s;
  int r, c;
  while(1){
    cin >> s;
    if(s == "ENDOFINPUT") break;
    cin >> r >> c;

    vector<vector<int> > a(r, vector<int>(c, 0));

    char d;
    for(int i = 0; i < r * c; i++){
      cin >> d;
      a[i / c][i % c] = d - '0';
    }
    for(int i = 0; i < r - 1; i++){
      for(int j = 0; j < c - 1; j++){
	cout << (a[i][j] + a[i][j + 1] +
		   a[i + 1][j] + a[i + 1][j + 1]) / 4;
      }
      cout << endl;
    }
    cin >> s;
  }
}
