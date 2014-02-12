#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv){
  string t;
  while(1){
    getline(cin, t);
    if(t == "#") break;
    int ret = 0;
    for(int i = 0; i < (int)t.length(); i++)
      if(isalpha(t[i]))
	ret += (i + 1) * (t[i] - 'A' + 1);
    cout << ret << endl;
  }
  return 0;
}