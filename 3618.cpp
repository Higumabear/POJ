#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int pl[50001];
int ml[50001];

int main(){

  for(int i = 0; i < 50001; i++){
    pl[i] = 114514810;
    ml[i] = 114514810;
  }

  int p = 0, m = 0;
  int T, N;
  cin >> T >> N;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if(tmp > 0) pl[p++] = tmp;
    else ml[m++] = tmp;
  }

  sort(pl, pl + p);
  sort(ml, ml + m, greater<int>());

  int vp = 0, vm = 0;
  int total = 0;

  int i;
  int prev = 0;
  for(i = 0; i < N; i++){
    if(abs(pl[vp]) > abs(ml[vm])){
      //cout << ml[vm];
      total += abs(ml[vm] - prev);
      prev = ml[vm++];
    }else{
      //cout << pl[vp];		
      total += abs(pl[vp] - prev);
      prev = pl[vp++];
    }
    
    //cout << "t : " << total << endl;
    if(total > T) break;
  }
  cout << i << endl;
  return 0;
}