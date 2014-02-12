#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int main()
{
  int N, Q;
  while(cin >> N >> Q){
    if(N == 0 && Q == 0) break;
    map<int, int> mp;
    for(int i = 0; i < N; i++){
      int nd;
      cin >> nd;
      for(int j = 0; j < nd; j++){
	int a; cin >> a;
	mp[a]++;
      }
    }

    int mag = 0, index;
    for(map<int, int>::iterator it = mp.begin(); 
	it != mp.end(); it++){
      if(mag < it->second){
	mag = it->second;
	index = it->first;
      }
    }
    if(mag < Q) index = 0;
    cout << index << endl;
  }
  return 0;
}