#include <iostream>
#include <string>
using namespace std;

int main(){
  string t;
  int cnt = 0; 
  while(getline(cin, t)){
    for(int i = 0; i < t.length(); i++){
      if(t[i] == '"' && cnt % 2 == 0){
	cout << "``";
	cnt++;
      }else if(t[i] == '"' && cnt % 2 == 1){
	cout << "''";
	cnt++;
      }else{
	cout << t[i];
      }
    }
    cout << endl;
  }
}