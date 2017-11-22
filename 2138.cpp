#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;


int N;
string s[1001];
vector<int> g[1001];

bool reach(string &s, string &t){
  int i = 0, j, df = 0;
  if(s.length() + 1 != t.length()) return false;
  for(j = 0; i < s.size() && j < t.size(); j++){
    if(s[i] != t[j]) i--;
    i++;
  }
  return j - i <= 1 && t.size() - s.size() == 1;
}

int main(){
  cin >> N >> s[0];
  for(int i = 0; i < N; i++) cin >> s[i + 1];
  for(int i = 0; i <= N; i++)
    for(int j = 0; j <= N; j++)
      if(reach(s[i], s[j])) g[i].push_back(j);

  int ans = 0;
  vector<bool> vis(N + 1, false);
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    if(s[ans].length() < s[v].length()) ans = v;
    vis[v] = true;
    for(int i = 0; i < g[v].size(); i++)
      if(!vis[g[v][i]])
	Q.push(g[v][i]);
  }
  cout << s[ans] << endl;
  return 0;
}
