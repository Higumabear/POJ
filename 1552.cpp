#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 10000;

int a[20];

void doubles(vector<int> res){
  int cnt = 0;
  int N = res.size();
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(i != j)
	if(res[i] * 2 == res[j]) cnt++;
  cout << cnt << endl;
}

int main()
{
  vector<int> res;
  int n;
  while(cin >> n, n != -1){
    if(n == 0){
      doubles(res);
      res.clear();
    }else{
      res.push_back(n);
    }
  }
  return 0;
}
