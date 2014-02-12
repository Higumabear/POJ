#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

struct Trie {
  int value;
  Trie *next[0x100];
  Trie() { fill(next, next+0x100, (Trie*)0); }
};

void *find(char *t, Trie *r) {
  for(int i = 0; t[i]; ++i) {
    char c = t[i];
    if(!r -> next[c]) r -> next[c] = new Trie;
    r = r -> next[c];
  }
  //return r;
}

bool exist(char *t, Trie *r) {
  for(int i = 0; t[i]; ++i) {
    char c = t[i];
    if(!r -> next[c]) return false;
    r = r -> next[c];
  }
  return true;
}

int main(){
  int M, N;
  scanf(" %d%d ", &M, &N);

  Trie t;
  
  for(int i = 0; i < M; i++){
    char s[100];
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = 0;
    find(s, &t);
  }

  int ret = 0;
  for(int i = 0; i < N; i++){
    char s[100];
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = 0;
    if(exist(s, &t)) ret++;
  }
  cout << ret << endl;
  return 0;
}