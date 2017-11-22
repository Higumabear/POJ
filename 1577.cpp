// Time-stamp: <Fri Mar 10 20:51:04 東京 (標準時) 2017>
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

struct bintree{
  struct node{
    char c;
    node *l, *r;
    node(char c): l(0), r(0), c(c) {}
  };
  node *root;
  bintree(): root(0) {}

  void add(char c){ add(root, c); }
  void add(node *v, char c){
    if(!v){
      root = new node(c);
      return;
    }
    if(v->c > c){
      if(!v->l) v->l = new node(c);
      else add(v->l, c);
    }else{
      if(!v->r) v->r = new node(c);
      else add(v->r, c);
    }
    return;
  }
  void func(node *v){
    if(v) putchar(v->c);
    if(v->l) func(v->l);
    if(v->r) func(v->r);
    return;
  }
  void print(){
    func(root);
  }
};

int main(int argc, char **argv){
  vector<string> leaf;
  while(1){
    string s;
    leaf.clear();
    while(cin >> s){
      if(s == "*" || s == "$") break;
      leaf.push_back(s);
    }
    reverse(ALL(leaf));
    
    bintree bt;
    for(int i = 0; i < leaf.size(); i++)
      for(int j = 0; j < leaf[i].size(); j++)
	bt.add(leaf[i][j]);
    
    bt.print();
    puts("");
    if(s == "$") break;
  }
  return 0;
}
