// Time-stamp: <Thu Mar 30 00:18:01 東京 (標準時) 2017>
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

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define rep(i,n) for (int i=0;i<(n);i++)


bool ho[320][320];

vector<int> G[3000];
int match[3000];
bool vis[3000];
int m,n,k;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

bool augment(int v){
  vis[v]=true;
  rep(i,G[v].size()){
    int to=G[v][i];
    if(match[to]==-1){
      match[to]=v;
      match[v]=to;
      return true;
    }
    if(vis[match[to]])continue;    
    if(augment(match[to])){
      match[to]=v;
      match[v]=to;
      return true;
    }
  }
  return false;
}

int main(){
  memset(match,-1,sizeof(match));
  cin>>m>>n>>k;
  rep(i,k){
    int x,y;
    cin>>x>>y;
    ho[y-1][x-1]=true;
  }
  rep(i,m){
    rep(j,n){
      if(ho[i][j])continue;
      rep(k,4){
        int ni=i+dx[k],nj=j+dy[k];
        if(ni<0 || m<=ni ||
           nj<0 || n<=nj ||
           ho[ni][nj])continue;
        G[i*n+j].push_back(ni*n+nj);
      }
    }
  }

  rep(i,n*m){
    if(match[i]!=-1 || ho[i/n][i%n])continue;
    memset(vis,0,sizeof(vis));
    if(!augment(i)){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}
