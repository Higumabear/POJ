#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main(){
  map<char, char> rep;
  rep['W'] = 'Q';rep['E'] = 'W';rep['R'] = 'E';rep['T'] = 'R';rep['Y'] = 'T';
  rep['U'] = 'Y';rep['I'] = 'U';rep['O'] = 'I';rep['P'] = 'O';rep['['] = 'P';
  rep[']'] = '[';rep['\\'] = ']';

  rep['S'] = 'A';rep['D'] = 'S';rep['F'] = 'D';
  rep['G'] = 'F';rep['H'] = 'G';rep['J'] = 'H';
  rep['K'] = 'J';rep['L'] = 'K';rep[';'] = 'L';rep['\''] = ';';
  rep['X'] = 'Z';rep['C'] = 'X';rep['V'] = 'C';rep['B'] = 'V';rep['N'] = 'B';
  rep['M'] = 'N';rep[','] = 'M';rep['.'] = ',';rep['/'] = '.';rep[' '] = ' ';
  rep['1'] = '`';rep['2'] = '1';rep['3'] = '2';rep['4'] = '3';rep['5'] = '4';
  rep['6'] = '5';rep['7'] = '6';rep['8'] = '7';rep['9'] = '8';rep['0'] = '9';
  rep['-'] = '0';rep['='] = '-';

  string s;
  while(getline(cin, s)){
    for(int i = 0; i < (int)s.length(); i++) cout << rep[s[i]];
    cout << endl;
  }
}