#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char **argv){
  string str;
  while(getline(cin, str)) cout << str << endl;
  return 0;
}
