#include <iostream>
#include <string>
using namespace std;

int main(){
  string s, t;
  while(cin >> s >> t){
    int N = s.length(), M = t.length();
    int j = 0;
    bool isok = false;
    for(int i = 0; i < M; i++){
      if(t[i] == s[j]) j++;
      if(j >= N) isok = true;
    }
    cout << (isok ? "Yes" : "No") << endl;
  }
}