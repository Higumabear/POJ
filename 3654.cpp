#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int perm[27];

void chmod(vector<int> idx, char op, string flag){
  for(int i = 0; i < idx.size(); i++){
    if(op == '=') perm[idx[i]] = 0;
    for(int j = 0; j < flag.size(); j++){
      if(op == '-')
	perm[idx[i]] &= ~(1 << (flag[j] - 'a'));
      else
	perm[idx[i]] |= (1 << (flag[j] - 'a'));
    }
  }
}

int main(){
  string s;
  int num = 0;
  while(cin >> s){
    memset(perm, 0, sizeof(perm));
    if(s == "#") break;
    for(int i = 0; i < s.size(); i++)
      if(s[i] == ',') s[i] = ' ';
    
    stringstream ss; ss << s;
    while(ss >> s){
      vector<int> idx;
      int i;
      for(i = 0; i < s.size(); i++){
	if(isupper(s[i])) idx.push_back(s[i] - 'A');
	else break; 
      }
      chmod(idx, s[i], s.substr(i + 1));
    }
    cout << ++num << ":";
    perm[26] = -1;
    int prev = perm[0];
    for(int i = 0; i < 27; i++){
      if(perm[i] == 0) continue;
      if(perm[i] != prev){
	for(int j = 0; j < 26; j++)
	  if(prev >> j & 1) cout << (char)(j + 'a'); 
	prev = perm[i];
      }
      if(i != 26) cout << (char)(i + 'A');
    }
    cout << endl;
  }
}
