#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
using namespace std;

vector<int> pr[10001];

int main(int argc, char **argv){
  int n;
  while(scanf("%d", &n) != EOF){
    priority_queue<int> q;
    for(int i = 0; i <= 10000; i++) pr[i].clear();
    

    int p, d;
    for(int i = 0; i < n; i++){
      scanf("%d %d", &p, &d);
      pr[d].push_back(p);
    }

    int ans = 0;
    for(int i = 10000; i >= 1; i--){
      for(int j = 0; j < pr[i].size(); j++) q.push(pr[i][j]);
      if(!q.empty()){
	ans += q.top(); 
	q.pop();
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}