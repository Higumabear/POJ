// Time-stamp: <Thu Jan 12 21:18:09 東京 (標準時) 2017>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <time.h>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;
int n;
vector<int> ans[200];
int arr[12];
void rec(int idx){
  int last = arr[idx];
  if(last > 100 || idx > 9) return;
  if(ans[last].size() > idx + 1){
    ans[last].resize(idx + 1);
    for(int i = 0; i < idx + 1; i++) ans[last][i] = arr[i];
  }

  for(int i = 0; i <= idx; i++){
    arr[idx + 1] = arr[idx] + arr[i];
    rec(idx + 1);
  }
  return;
}

int main(int argc, char **argv){
  fill(ans, ans + 101, vector<int>(100, 0));
  arr[0] = 1;
  rec(0);
  while(cin >> n, n){
    //for(int n = 1; n <= 100; n++){
    for(int i = 0; i < ans[n].size(); i++) 
      cout << ans[n][i] << " ";
    cout << endl;
  }
  // vector<vector<int> > node(101, vector<int>(200, INF));
  // vector<int> init(1); init[0] = 1;
  // q.push(init);
  // node[1] = init;
  // while(!q.empty()){
  //   vector<int> path = q.front();
  //   int len = path.size();
  //   q.pop();
  //   if(len >= 9) continue;
  //   for(int i = 0; i < path.size(); i++){
  //     int next = path[path.size() - 1] + path[i];
  //     if(next > 100) break;
  //     vector<int> tmp = path;
  //     tmp.push_back(next);
  //     q.push(tmp);
  //     if(node[next].size() > tmp.size())
  // 	node[next] = tmp;
  //   }
  // }
  //while(cin >> n, n){
  // for(int n = 1; n <= 100; n++){
  //   queue<vector<int> > q;
  //   vector<int> init(2); 
  //   init[0] = 1, init[1] = 2;
  //   q.push(init);
  //   vector<int> ans;
  //   while(!q.empty()){
  //     vector<int> e = q.front(); q.pop();
  //     int back = e.back();
  //     if(back == n || back == n - 1 || back == n - 2){
  // 	ans = e; break;
  //     }
  //     if(e.back() > n || e.size() >= 10) continue;
  //     for(int i = 0; i < e.size(); i++){
  // 	if(e.back() + e[i] > n) break;
  // 	vector<int> tmp = e;
  // 	tmp.push_back(e.back() + e[i]);
  // 	q.push(tmp);
  //     }
  //   }
  //   for(int i = 0; i < ans.size(); i++) 
  //     cout << ans[i] << " ";
  //   cout << endl;
  // }
  return 0;
}
