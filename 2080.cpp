#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool leap(int y){
  return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);   
}

int main(int argc, char **argv){
  int N;
  string day[7] = {"Friday","Saturday", "Sunday", "Monday", "Tuesday", 
		   "Wednesday", "Thursday"};
  int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  while(cin >> N, N >= 0){
    N++;
    int T = N;
    int year = 2000;

    int total = leap(year) ? 366 : 365;
    while(N - total > 0){
      N -= total;
      year++;
      total = leap(year) ? 366 : 365;
    }
  
    int mon = 1;
    for(mon = 1; mon <= 12; mon++){
      int d = (mon == 2 && leap(year)) ? 29 : days[mon - 1];
      if(N <= d) break;
      N -= d;
    }
    printf("%d-%02d-%02d %s\n", year, mon, N, day[T%7].c_str());
  }
}