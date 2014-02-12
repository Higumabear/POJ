#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv){
  int N; cin >> N;
  while(N--){
    string s1, s2;
    cin >> s1 >> s2;

    bool sub = false;

    //normal order
    int j = 0;
    for(int i = 0; i < (int)s1.length(); i++){
      if(s1[i] == s2[j]) j++;
      if(j >= (int)s2.length()) sub = true;
    }

    reverse(s2.begin(), s2.end());

    //reversed order
    j = 0;
    for(int i = 0; i < (int)s1.length(); i++){
      if(s1[i] == s2[j]) j++;
      if(j >= (int)s2.length()) sub = true;
    }

    cout << (sub ? "YES" : "NO") << endl;
  }
  return 0;
}