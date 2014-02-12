#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;

int out[26];
int num[26];

int main(int argc, char **argv){
  string input;
  int maxmag = 0;

  fill(num, num + 26, 0);
  fill(out, out + 26, 0);
  for(int i = 0; i < 4; i++){
    getline(cin, input);
    for(int j = 0; j < (int)input.length(); j++){
      if(isalpha(input[j]))
	maxmag = max(maxmag, ++num[input[j] - 'A']);
    }
  }

  //各行は何文字目まで出力するか
  for(int i = 0; i < maxmag; i++){
    for(int j = 0; j < 26; j++){
      if(num[j] >= maxmag - i) out[i] = j;
    }
  }

  //実際に出力
  for(int i = 0; i < maxmag; i++){
    for(int k = 0; k <= out[i]; k++){
      if(num[k] >= maxmag - i)
	cout << "*";
      else
	cout << " ";

      if(k != out[i]) cout << " ";
    }
    cout << endl;
  }
  for(int i = 0; i < 26; i++){
    cout << (char)(i + 'A');
    if(i != 25) cout << " ";
  }
  cout << endl;
  
  return 0;
}