#include <stdio.h>
#include <iostream>
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
  int n;
  cin >> n;
  vector<string> board(100);
  for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
      board[i] += "w";
  for(int i = 0; i < n; ++i){
    string command;
    int x, y, L;
    cin >> command >> x >> y >> L;
    x--; y--;
    if(command == "BLACK"){
      for(int p = y; p < y + L; p++)
        for(int q = x; q < x + L; q++)
          board[p][q] = 'b';
    }else if(command == "TEST"){
      int cnt = 0;
      for(int p = y; p < y + L; p++)
        for(int q = x; q < x + L; q++)
          if(board[p][q] == 'b') cnt++;
      cout << cnt << endl;
    }else{
      for(int p = y; p < y + L; p++)
        for(int q = x; q < x + L; q++)
          board[p][q] = 'w';
    }
  }
  return 0;
}