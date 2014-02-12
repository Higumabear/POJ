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
#include <cstring>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

vector<int> G[10000];

int n;
int num[10000];
bool visited[10000];
set<int> ans;

int dfs(int root){
  int maxval = 0;
  int ret = 1;
  visited[root] = true;
  for(int i = 0; i < (int)G[root].size(); i++){
    if(visited[G[root][i]]) continue;
    int df = dfs(G[root][i]);
    maxval = max(maxval, df);
    ret += df;
  }
  maxval = max(maxval, n - ret);
  if(maxval * 2 <= n)
    ans.insert(root);
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }
  dfs(0);
  if(ans.empty())
    cout << "NONE" << endl;
  else{
    set<int>::iterator it = ans.begin();
    for(; it != ans.end(); it++)
      cout << *it + 1 << endl;
  }
  return 0;
}
