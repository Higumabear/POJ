#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


long long x[100000];
int N, C;

int cow(long long n){
  int prev = x[0];
  int l = 1;
  for(int i = 1; i < C; i++){
    while(l < N && x[l] - prev < n) l++;
    if(l == N) return -1;
    prev = x[l];
  }
  return 1;
}

int main(int argc, char **argv){
  cin >> N >> C;
  for(int i = 0; i < N; i++) cin >> x[i];

  sort(x, x + N);
  
  long long ub = 1000000000;
  long long lb = 0;
  long long mid = (ub + lb) / 2;
  while(ub - lb > 1){
    mid = (ub + lb) / 2;
    if(cow(mid) == 1){
      lb = mid;
    }else {
      ub = mid;
    }
  }
  cout << lb << endl;
  return 0;
}