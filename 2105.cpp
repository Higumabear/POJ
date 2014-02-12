#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    string IP;
    cin >> IP;
    for(int i = 0; i < 4; i++){
      int addr = 0;
      for(int j = 0; j < 8; j++){
        if(IP[i * 8 + j] == '1')
          addr += (int)pow((double)2, (7 - j));
      }
      cout << addr;
      if(i != 3) cout << ".";
      else cout << endl;
    }
  }
  return 0;
}