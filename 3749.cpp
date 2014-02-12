#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv){
  string a;
  while(cin >> a, a != "ENDOFINPUT"){
    string line;
    cin.ignore();
    getline(cin, line);
    string s;
    for(int i = 0; i < (int)line.length(); i++){
      if('A' <= line[i] && line[i] <= 'Z'){
	s += (char)((line[i] - 'A' + 21) % 26 + 'A');
      }else s += line[i];
    }
    cout << s << endl;
    cin >> a;
  }
  return 0;
}