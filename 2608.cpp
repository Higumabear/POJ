#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  vector<string> code;

  code.push_back("AEIOUHWY");
  code.push_back("BFPV");
  code.push_back("CGJKQSXZ");
  code.push_back("DT");
  code.push_back("L");
  code.push_back("MN");
  code.push_back("R");

  map<char, char> repr;
  for(int i = 0; i < (int)code.size(); i++){
    for(int j = 0; j < (int)code[i].length(); j++){
      repr[code[i][j]] = (char)(i + '0');
    }
  }

  string t;
  while(cin >> t){
    string f;
    for(int i = 0; i < (int)t.length(); i++){
      f += repr[t[i]];
    }
    f.erase(unique(f.begin(), f.end()), f.end());

    for(int i = 0; i < (int)f.length(); i++){
      if(f[i] != '0') cout << f[i];
    }
    cout << endl;
  }
  return 0;
}